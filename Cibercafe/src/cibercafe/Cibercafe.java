package cibercafe;

import java.io.Serializable;
import utils.Utils;
import java.util.ArrayList;
import java.util.Date;
import java.util.LinkedList;
import java.util.List;
import users.User;
import users.AsociatedUser;

/**
 *
 * @author teamSix
 */
public class Cibercafe implements Serializable{
    private int cantMaq;
    private User[] maqs;
    private List<AsociatedUser> usuariosAsociados;
    private LinkedList<Integer> disp;
    private LinkedList<User> queue;
    private ArrayList<User> allCostumers;
    private LinkedList<Date> timer;
    private User longerTimeUser;
    private long longerTime;
    
    
    public Cibercafe(int cantMaq){
        this.cantMaq = cantMaq;
        
        maqs = new User[cantMaq];
        usuariosAsociados = new ArrayList<>();
        disp = new LinkedList<>();
        queue = new LinkedList<>();
        allCostumers = new ArrayList<>();
        
        for(int i=0; i < cantMaq; i++)
            disp.add(i);
        
        timer = new LinkedList<>();
        longerTime = 0;
    }
    
    public User processNext(){
        int maq = disp.pollFirst();
        User current = queue.pollFirst();
        
        current.setMaq(maq);
        maqs[maq] = current;
        allCostumers.add(current);
        
        return current;
    }
    
    public void exitUser(int maq){
        disp.add(maq);
        maqs[maq] = null;
    }
    
    public void registerAsociated(AsociatedUser newUser) throws ExistingUserException{
        for(AsociatedUser usuario: usuariosAsociados)
            if( usuario.equals(newUser) )
                throw new ExistingUserException();
        
        usuariosAsociados.add(newUser);
    }
    
    public void registerAsociated(String nombre, String cc, char cat, int years) throws ExistingUserException{
        AsociatedUser newUser = new AsociatedUser(nombre, cc, cat, -1, years);
        
        registerAsociated(newUser);
    }
    
    public void enqueueUser(User user){
        queue.addLast(user);
    }
    
    public boolean hasAvaliableMaqs() { return !disp.isEmpty(); }
    
    public List getAsociatedUsers(){ return usuariosAsociados; }
    public LinkedList getQueue(){ return queue; }
    public Object[] getArrayofAsociatedUsers(){ return Utils.getArrayOfObjects(usuariosAsociados); }
    public User[] getUsersInMaqs(){ return maqs; }
    public LinkedList<Integer> getDisp() { return disp; }
    public int getCantMaq() { return cantMaq; }
    public ArrayList<User> getAllCostumers() { return allCostumers; }
    public LinkedList<Date> getTimer() { return timer; }
    public User getLongerTimeUser() { return longerTimeUser; }
    public long getLongerTime() { return longerTime; }

    public void setLongerTimeUser(User longerTimeUser) {
        this.longerTimeUser = longerTimeUser;
    }

    public void setLongerTime(long longerTime) {
        this.longerTime = longerTime;
    }
    
    
}
