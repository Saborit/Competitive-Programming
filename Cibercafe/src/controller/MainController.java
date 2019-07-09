/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package controller;

import cibercafe.Cibercafe;
import cibercafe.ExistingUserException;
import java.awt.Frame;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;
import javax.swing.JDialog;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import static javax.swing.WindowConstants.DISPOSE_ON_CLOSE;
import users.User;
import users.AsociatedUser;
import utils.CCFFileFilter;
import utils.Utils;
import visual.AddUserFrame;
import visual.MainFrame;
import visual.AddServiceFrame;
import visual.ExitUserDialog;
import visual.IntTextDialog;
import visual.TotalsFrame;
import visual.UserInfoDialog;
import visual.UsersFrame;

public class MainController {
    private MainFrame owner;
    private File currentDirectory, currentFile;
    private Cibercafe cibercafe;
    
    public MainController(MainFrame owner){
        this.owner = owner;
    }
    
   /**
    *
    * Interface System-User Methods
    * 
    */ 
    
    public AsociatedUser registerAsociatedUserFromAddUserFrame(AddUserFrame frame) throws ExistingUserException{
        AsociatedUser user;
        char cat;
        
        if( frame.getList().isSelectedIndex(0) ) cat = 'd'; 
        else if( frame.getList().isSelectedIndex(1) ) cat = 'p';
        else cat = 'b';
            
        user = new AsociatedUser(frame.getNameTextField().getText(), frame.getCardTextField().getText(), 
                                       cat, -1, Integer.parseInt(frame.getYearsTextField().getText()));
        
        cibercafe.registerAsociated(user);
        
        return user;
    }
    
    public void enQueueUser(User user) {
        cibercafe.enqueueUser(user);
        Date date = new Date();
        cibercafe.getTimer().addLast(date);
        
        owner.getProcessNextButton().setEnabled(owner.canEnableProcessNext());
        owner.setQueueList(cibercafe.getQueue());
    }
    
    public void exitUser(int maq) {
        User[] users = cibercafe.getUsersInMaqs();
        users[maq - 1] = null;
        cibercafe.getDisp().add(maq-1);
    }
    
    public void saveWithoutAsking() throws IOException{
        if( currentFile == null || !currentFile.getAbsolutePath().endsWith(".ccf") )
            launchSaveOptions(owner);
        else
            dump(currentFile.toString());
    } 
    
    public void updateProcessNextButton(){
        owner.getProcessNextButton().setEnabled(owner.canEnableProcessNext());
    }
    
    public void processNext() {
        User user = cibercafe.processNext();
        Date initDate = cibercafe.getTimer().pollFirst();
        Date finalDate = new Date();
        
        long diff = finalDate.getTime() - initDate.getTime();
        
        if( diff > cibercafe.getLongerTime() ){
            cibercafe.setLongerTimeUser(user);
            cibercafe.setLongerTime(diff);;
        }        
    }

    
  /**
   *
   * Launchers
   * 
   */
    
    public void launchAddUsersFrame(Frame caller){
        AddUserFrame frame = new AddUserFrame(owner);
        
        frame.setLocation(Utils.innerPosition(caller, frame));
                
        Object[] list = {"Dorada", "Plateada", "Bronceada"};
        frame.getList().setListData(list);
                
        frame.setVisible(true);
        frame.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
    }
     
    public void launchUsersFrame(Frame caller, List<User> users){
        UsersFrame frame = new UsersFrame(owner, users);
        
        frame.setLocation(Utils.innerPosition(caller, frame));
        frame.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        frame.setVisible(true);
    }
    
    public void launchUsersFrame(Frame caller, User[] users){
        ArrayList<User> list = new ArrayList();
        
        for(User user: users)
            if( user != null )
                list.add(user);

        launchUsersFrame(caller, list);
    }
    
    public void launchAddServiceFrame(Frame caller){
        AddServiceFrame frame = new AddServiceFrame((MainFrame)caller);
        frame.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        frame.setLocation(Utils.innerPosition(caller, frame));
        frame.setVisible(true);
    }
    
    public void launchTotalsFrame(Frame caller) {
        TotalsFrame frame = new TotalsFrame(cibercafe);
        
        frame.setLocation(Utils.innerPosition(frame));
        frame.setVisible(true);
        frame.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
    }
    
    public void launchNewInstanceDialog(Frame caller, JDialog newDialog){
        newDialog.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        newDialog.setLocation(500, 300);
        newDialog.setVisible(true);
    }
    
    public void launchErrorDialog(Frame caller, Exception ex) {
        String message = ex.getMessage();
        
        if( ex instanceof IOException )
            message = "Error al leer/escribir el archivo";
        else if( ex instanceof ClassNotFoundException )
            message = "Error de compatibilidad entre clases";
        
        JOptionPane.showMessageDialog(caller, message, "Error", JOptionPane.ERROR_MESSAGE);
    }
    
    public void launchUserInfoDialog(Frame caller, User user) {
        UserInfoDialog dialog = new UserInfoDialog(owner, this, user, true);
        dialog.setLocation(Utils.innerPosition(caller, dialog));
        dialog.getListOfSevices().setListData(Utils.getArrayOfObjects(user.getServices()));
        dialog.setVisible(true);
    }
    
    public void launchIntTextDialog(AddServiceFrame caller) {
        IntTextDialog dialog = new IntTextDialog(caller, true);
        dialog.setLocation(Utils.innerPosition(caller, dialog));
        dialog.getIntTextPane().setText(caller.getText());
        dialog.setVisible(true);
    }

    public void launchExitUserDialog(Frame caller) {
        ExitUserDialog dialog = new ExitUserDialog(caller, this, cibercafe.getUsersInMaqs());
        dialog.setLocation(Utils.innerPosition(caller, dialog));
        dialog.setVisible(true);
    }  
    
    public void showLongerTimeDialog(Frame caller) {
        if( cibercafe.getLongerTimeUser() != null )
            JOptionPane.showMessageDialog(
                caller, 
                "El usuario que más tiempo ha esperado por una máquina \nes " + cibercafe.getLongerTimeUser() + 
                    ". Ha esperado " + (int)(cibercafe.getLongerTime()/60000) + " minutos y " + (int)(cibercafe.getLongerTime()/1000) % 60 + " segundos", 
                "Usuario que más tiempo ha esperado", 
                JOptionPane.INFORMATION_MESSAGE);
        else
            JOptionPane.showMessageDialog(
                caller,
                "No se ha registrado ningún usuario",    
                "Usuario que más tiempo ha esperado", 
                JOptionPane.INFORMATION_MESSAGE);
    }
    
    public void launchSaveOptions(Frame caller){
        JFileChooser fileChooser = new JFileChooser(currentDirectory);
        fileChooser.setFileFilter(new CCFFileFilter());
        fileChooser.approveSelection();
        fileChooser.setDialogTitle("Seleccione el nombre del archivo");
        
        if( fileChooser.showDialog(caller, "Guardar") == JFileChooser.APPROVE_OPTION ){
            try{
                if( fileChooser.getSelectedFile().toString().endsWith(".ccf") )
                    dump(fileChooser.getSelectedFile().toString());
                else
                    dump(fileChooser.getSelectedFile().toString() + ".ccf");
                currentDirectory = fileChooser.getCurrentDirectory();
                currentFile = fileChooser.getSelectedFile();    
            }
            catch(IOException ioe){
                System.out.println("Exception Saving File: " + ioe.getMessage());
                launchErrorDialog(caller, ioe);
            }    
        }
    }
    public void launchLoadOptions(Frame caller){
        JFileChooser fileChooser = new JFileChooser(currentDirectory);
        fileChooser.setFileFilter(new CCFFileFilter());
        fileChooser.approveSelection();
        fileChooser.setDialogTitle("Seleccione el nombre del archivo");
        
        if( fileChooser.showDialog(caller, "Abrir") == JFileChooser.APPROVE_OPTION ){
            try{
                setNewCibercafe(load(fileChooser.getSelectedFile().toString()));
                
                currentDirectory = fileChooser.getCurrentDirectory();
                currentFile = fileChooser.getSelectedFile();
            }
            catch(IOException ioe){
                System.out.println("Exception Loading File: " + ioe.getMessage());
                JOptionPane.showMessageDialog(caller, "Error cargando el archivo", "Error", JOptionPane.ERROR_MESSAGE);
            }
            catch(ClassNotFoundException cnfe){}
        }
    }
    
    public void saveAsociatedOptions(Frame caller){
        JFileChooser fileChooser = new JFileChooser(currentDirectory);
        fileChooser.approveSelection();
        fileChooser.setDialogTitle("Seleccione el nombre del archivo");
        
        if( fileChooser.showDialog(caller, "Guardar") == JFileChooser.APPROVE_OPTION ){
            try{
                saveInTextFile(fileChooser.getSelectedFile().getAbsolutePath());
          
                currentDirectory = fileChooser.getCurrentDirectory();
                currentFile = fileChooser.getSelectedFile();
            
                JOptionPane.showMessageDialog(caller, "Los datos de los asociados han sido guardados correctamente", "Información", JOptionPane.INFORMATION_MESSAGE);
            }
            catch(IOException ioe){
                System.out.println("Exception Saving Text File: " + ioe.getMessage());
                launchErrorDialog(caller, ioe);
            }
        } 
    }
            
   /**
    *
    * Setters-Getters
    * 
    */
    
    public Cibercafe getCibercafe(){ return cibercafe; }

    public void setNewCibercafe(Cibercafe ciber) {
        cibercafe = ciber;
        owner.setQueueList(cibercafe.getQueue());
        owner.getProcessNextButton().setEnabled(owner.canEnableProcessNext());
    }
    
    public void setNewCibercafe(int maqs) {
        setNewCibercafe(new Cibercafe(maqs));
    }

   /**
    *
    * File Persistence
    *
    */ 
    private void dump(String fileName) throws FileNotFoundException, IOException{
        ObjectOutputStream f = new ObjectOutputStream(new FileOutputStream(fileName));
        
        f.writeObject(cibercafe);
        f.close();
    }
    
    private Cibercafe load(String fileName) throws IOException, ClassNotFoundException{
        ObjectInputStream f = new ObjectInputStream(new FileInputStream(fileName));
        
        Object obj = f.readObject();
        
        f.close();
        return (Cibercafe)obj;
    }
    
    private void saveInTextFile(String fileName) throws FileNotFoundException{
        PrintWriter f = new PrintWriter(fileName);
        
        String category;
        AsociatedUser user;
        f.write(cibercafe.getAsociatedUsers().size() + "\n");
        for(Object obj: cibercafe.getAsociatedUsers()){
            user = (AsociatedUser)obj;
            
            switch (user.getCategory()) {
                case 'd':
                    category = "Dorada";
                    break;
                case 'p':
                    category = "Plateada";
                    break;
                default:
                    category = "Bronceada";
                    break;
            }
            
            f.printf("Nombre = %s  CreditC = %s  Máquina = %d  Category = %s  Años = %d\n",
                    user.getName(),
                    user.getCreditCard(),
                    user.getMaq(),
                    category,
                    user.getYears()
            );
        }
        
        f.close();
    }
    
}
