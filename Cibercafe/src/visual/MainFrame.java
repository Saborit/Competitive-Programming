/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package visual;

import cibercafe.Cibercafe;
import controller.MainController;
import java.awt.Image;
import java.awt.Toolkit;
import java.io.IOException;
import java.util.List;
import javax.swing.JButton;
import users.User;
import utils.Utils;

public class MainFrame extends javax.swing.JFrame {
    public MainController main = new MainController(this);
    
    public MainFrame() {
        initComponents();
        setLocation(200, 200);
        
        main.setNewCibercafe(10);
        
    
        processNextButton.setEnabled(canEnableProcessNext());
        infoButton.setEnabled(false);
    }
    
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        newInstanceDialog = new javax.swing.JDialog();
        jLabel1 = new javax.swing.JLabel();
        finalizeOpenDialog = new javax.swing.JButton();
        cancelOpenDialog = new javax.swing.JButton();
        textOpenDialog = new javax.swing.JTextField();
        label1 = new java.awt.Label();
        jScrollPane2 = new javax.swing.JScrollPane();
        queueList = new javax.swing.JList();
        jLabel2 = new javax.swing.JLabel();
        processNextButton = new javax.swing.JButton();
        exitUserButton = new javax.swing.JButton();
        infoButton = new javax.swing.JButton();
        jLabel3 = new javax.swing.JLabel();
        jButton1 = new javax.swing.JButton();
        jMenuBar1 = new javax.swing.JMenuBar();
        fileMenu = new javax.swing.JMenu();
        newDayMenuItem = new javax.swing.JMenuItem();
        openMenuItem = new javax.swing.JMenuItem();
        saveMenuItem = new javax.swing.JMenuItem();
        saveAsMenuItem = new javax.swing.JMenuItem();
        saveAsociatedMenuItem = new javax.swing.JMenuItem();
        closeMenuItem = new javax.swing.JMenuItem();
        userMenu = new javax.swing.JMenu();
        regUserMenuItem = new javax.swing.JMenuItem();
        jSeparator1 = new javax.swing.JPopupMenu.Separator();
        showAllMenuItem = new javax.swing.JMenuItem();
        showCurrentUsersMenuItem = new javax.swing.JMenuItem();
        jSeparator2 = new javax.swing.JPopupMenu.Separator();
        jMenuItem1 = new javax.swing.JMenuItem();
        addServiceMenu = new javax.swing.JMenu();
        addServiceMenuItem = new javax.swing.JMenuItem();
        finacesMenu = new javax.swing.JMenu();
        earningsMenuItem = new javax.swing.JMenuItem();

        newInstanceDialog.setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        newInstanceDialog.setMinimumSize(new java.awt.Dimension(342, 152));

        jLabel1.setText("Número de Máquinas:");

        finalizeOpenDialog.setText("Finalizar");
        finalizeOpenDialog.setDefaultCapable(false);
        finalizeOpenDialog.setEnabled(false);
        finalizeOpenDialog.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                finalizeOpenDialogActionPerformed(evt);
            }
        });

        cancelOpenDialog.setText("Cancelar");
        cancelOpenDialog.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cancelOpenDialogActionPerformed(evt);
            }
        });

        textOpenDialog.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyTyped(java.awt.event.KeyEvent evt) {
                textOpenDialogKeyTyped(evt);
            }
            public void keyReleased(java.awt.event.KeyEvent evt) {
                textOpenDialogKeyReleased(evt);
            }
        });

        label1.setFont(new java.awt.Font("SansSerif", 1, 12)); // NOI18N
        label1.setForeground(new java.awt.Color(49, 54, 59));
        label1.setText("Nuevo Archivo...");

        javax.swing.GroupLayout newInstanceDialogLayout = new javax.swing.GroupLayout(newInstanceDialog.getContentPane());
        newInstanceDialog.getContentPane().setLayout(newInstanceDialogLayout);
        newInstanceDialogLayout.setHorizontalGroup(
            newInstanceDialogLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(newInstanceDialogLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(newInstanceDialogLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(label1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(newInstanceDialogLayout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addGap(58, 58, 58)
                        .addComponent(textOpenDialog, javax.swing.GroupLayout.PREFERRED_SIZE, 64, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(newInstanceDialogLayout.createSequentialGroup()
                        .addGap(87, 87, 87)
                        .addComponent(finalizeOpenDialog)
                        .addGap(32, 32, 32)
                        .addComponent(cancelOpenDialog)))
                .addContainerGap(71, Short.MAX_VALUE))
        );
        newInstanceDialogLayout.setVerticalGroup(
            newInstanceDialogLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(newInstanceDialogLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(label1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 27, Short.MAX_VALUE)
                .addGroup(newInstanceDialogLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(textOpenDialog, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(newInstanceDialogLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(finalizeOpenDialog)
                    .addComponent(cancelOpenDialog))
                .addGap(32, 32, 32))
        );

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Gestión de un Cibercafé");

        queueList.setToolTipText("");
        queueList.addPropertyChangeListener(new java.beans.PropertyChangeListener() {
            public void propertyChange(java.beans.PropertyChangeEvent evt) {
                queueListPropertyChange(evt);
            }
        });
        queueList.addListSelectionListener(new javax.swing.event.ListSelectionListener() {
            public void valueChanged(javax.swing.event.ListSelectionEvent evt) {
                queueListValueChanged(evt);
            }
        });
        jScrollPane2.setViewportView(queueList);

        jLabel2.setText("Cola de Usuarios:");

        processNextButton.setText("Procesar Siguiente");
        processNextButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                processNextButtonActionPerformed(evt);
            }
        });

        exitUserButton.setText("Salida de Usuario");
        exitUserButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                exitUserButtonActionPerformed(evt);
            }
        });

        infoButton.setText("Información");
        infoButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                infoButtonActionPerformed(evt);
            }
        });

        jLabel3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/resources/logo_big.png"))); // NOI18N
        jLabel3.setMaximumSize(new java.awt.Dimension(200, 200));

        jButton1.setText("Usuarios Actuales");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        fileMenu.setText("Archivo");
        fileMenu.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                fileMenuActionPerformed(evt);
            }
        });

        newDayMenuItem.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_N, java.awt.event.InputEvent.CTRL_MASK));
        newDayMenuItem.setText("Nuevo");
        newDayMenuItem.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                newDayMenuItemActionPerformed(evt);
            }
        });
        fileMenu.add(newDayMenuItem);

        openMenuItem.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_O, java.awt.event.InputEvent.CTRL_MASK));
        openMenuItem.setText("Abrir");
        openMenuItem.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                openMenuItemActionPerformed(evt);
            }
        });
        fileMenu.add(openMenuItem);

        saveMenuItem.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_S, java.awt.event.InputEvent.CTRL_MASK));
        saveMenuItem.setText("Guardar");
        saveMenuItem.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                saveMenuItemActionPerformed(evt);
            }
        });
        fileMenu.add(saveMenuItem);

        saveAsMenuItem.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_S, java.awt.event.InputEvent.SHIFT_MASK | java.awt.event.InputEvent.CTRL_MASK));
        saveAsMenuItem.setText("Guardar Como...");
        saveAsMenuItem.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                saveAsMenuItemActionPerformed(evt);
            }
        });
        fileMenu.add(saveAsMenuItem);

        saveAsociatedMenuItem.setText("Guardar Asociados");
        saveAsociatedMenuItem.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                saveAsociatedMenuItemActionPerformed(evt);
            }
        });
        fileMenu.add(saveAsociatedMenuItem);

        closeMenuItem.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_Q, java.awt.event.InputEvent.CTRL_MASK));
        closeMenuItem.setText("Cerrar");
        closeMenuItem.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                closeMenuItemActionPerformed(evt);
            }
        });
        fileMenu.add(closeMenuItem);

        jMenuBar1.add(fileMenu);

        userMenu.setText("Usuarios");

        regUserMenuItem.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_U, java.awt.event.InputEvent.CTRL_MASK));
        regUserMenuItem.setText("Registrar un Usuario");
        regUserMenuItem.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                regUserMenuItemActionPerformed(evt);
            }
        });
        userMenu.add(regUserMenuItem);
        userMenu.add(jSeparator1);

        showAllMenuItem.setText("Mostrar Asociados");
        showAllMenuItem.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                showAllMenuItemActionPerformed(evt);
            }
        });
        userMenu.add(showAllMenuItem);

        showCurrentUsersMenuItem.setText("Mostrar Usuarios Actuales");
        showCurrentUsersMenuItem.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                showCurrentUsersMenuItemActionPerformed(evt);
            }
        });
        userMenu.add(showCurrentUsersMenuItem);
        userMenu.add(jSeparator2);

        jMenuItem1.setText("Mayor Tiempo de Espera");
        jMenuItem1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem1ActionPerformed(evt);
            }
        });
        userMenu.add(jMenuItem1);

        jMenuBar1.add(userMenu);

        addServiceMenu.setText("Servicios");

        addServiceMenuItem.setText("Agregar un Servicio");
        addServiceMenuItem.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                addServiceMenuItemActionPerformed(evt);
            }
        });
        addServiceMenu.add(addServiceMenuItem);

        jMenuBar1.add(addServiceMenu);

        finacesMenu.setText("Finanzas");

        earningsMenuItem.setText("Finanzas Totales");
        earningsMenuItem.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                earningsMenuItemActionPerformed(evt);
            }
        });
        finacesMenu.add(earningsMenuItem);

        jMenuBar1.add(finacesMenu);

        setJMenuBar(jMenuBar1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 437, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel2))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 54, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(27, 27, 27))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(exitUserButton, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(infoButton, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(processNextButton, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jButton1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addGap(38, 38, 38))))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, layout.createSequentialGroup()
                        .addGap(44, 44, 44)
                        .addComponent(jLabel2)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(jScrollPane2))
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jLabel3, javax.swing.GroupLayout.DEFAULT_SIZE, 263, Short.MAX_VALUE)
                        .addGap(25, 25, 25)
                        .addComponent(jButton1)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(processNextButton)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(exitUserButton)
                        .addGap(12, 12, 12)
                        .addComponent(infoButton)))
                .addGap(34, 34, 34))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void regUserMenuItemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_regUserMenuItemActionPerformed
        main.launchAddUsersFrame(this);
    }//GEN-LAST:event_regUserMenuItemActionPerformed

    private void showAllMenuItemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_showAllMenuItemActionPerformed
        main.launchUsersFrame(this, main.getCibercafe().getAsociatedUsers());
    }//GEN-LAST:event_showAllMenuItemActionPerformed

    private void fileMenuActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_fileMenuActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_fileMenuActionPerformed

    private void closeMenuItemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_closeMenuItemActionPerformed
        System.exit(0);
    }//GEN-LAST:event_closeMenuItemActionPerformed

    private void newDayMenuItemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_newDayMenuItemActionPerformed
        main.launchNewInstanceDialog(this, newInstanceDialog);
    }//GEN-LAST:event_newDayMenuItemActionPerformed

    private void openMenuItemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_openMenuItemActionPerformed
        main.launchLoadOptions(this);
    }//GEN-LAST:event_openMenuItemActionPerformed

    private void saveMenuItemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_saveMenuItemActionPerformed
        try {
            main.saveWithoutAsking();
        } 
        catch(IOException ex){
            main.launchErrorDialog(this, ex);
        }
    }//GEN-LAST:event_saveMenuItemActionPerformed

    private void finalizeOpenDialogActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_finalizeOpenDialogActionPerformed
        main.setNewCibercafe(Integer.parseInt(textOpenDialog.getText()));
        newInstanceDialog.setVisible(false);
    }//GEN-LAST:event_finalizeOpenDialogActionPerformed

    private void cancelOpenDialogActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cancelOpenDialogActionPerformed
        newInstanceDialog.setVisible(false);
        textOpenDialog.setText("");
    }//GEN-LAST:event_cancelOpenDialogActionPerformed

    private void textOpenDialogKeyTyped(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_textOpenDialogKeyTyped
                
    }//GEN-LAST:event_textOpenDialogKeyTyped

    private void textOpenDialogKeyReleased(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_textOpenDialogKeyReleased
        finalizeOpenDialog.setEnabled( Utils.isNonNegativeInteger(textOpenDialog.getText()) );
    }//GEN-LAST:event_textOpenDialogKeyReleased

    private void saveAsMenuItemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_saveAsMenuItemActionPerformed
        main.launchSaveOptions(this);
    }//GEN-LAST:event_saveAsMenuItemActionPerformed

    private void addServiceMenuItemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_addServiceMenuItemActionPerformed
        main.launchAddServiceFrame(this);
    }//GEN-LAST:event_addServiceMenuItemActionPerformed

    private void processNextButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_processNextButtonActionPerformed
        main.processNext();
        
        setQueueList(main.getCibercafe().getQueue());
        processNextButton.setEnabled(canEnableProcessNext());
    }//GEN-LAST:event_processNextButtonActionPerformed

    private void queueListValueChanged(javax.swing.event.ListSelectionEvent evt) {//GEN-FIRST:event_queueListValueChanged
        infoButton.setEnabled(queueList.getSelectedIndex() != -1);
    }//GEN-LAST:event_queueListValueChanged

    private void queueListPropertyChange(java.beans.PropertyChangeEvent evt) {//GEN-FIRST:event_queueListPropertyChange
        
    }//GEN-LAST:event_queueListPropertyChange

    private void exitUserButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_exitUserButtonActionPerformed
        main.launchExitUserDialog(this);
    }//GEN-LAST:event_exitUserButtonActionPerformed

    private void showCurrentUsersMenuItemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_showCurrentUsersMenuItemActionPerformed
        main.launchUsersFrame(this, main.getCibercafe().getUsersInMaqs());
    }//GEN-LAST:event_showCurrentUsersMenuItemActionPerformed

    private void infoButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_infoButtonActionPerformed
        main.launchUserInfoDialog(this, (User)queueList.getSelectedValue());
    }//GEN-LAST:event_infoButtonActionPerformed

    private void earningsMenuItemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_earningsMenuItemActionPerformed
        main.launchTotalsFrame(this);
    }//GEN-LAST:event_earningsMenuItemActionPerformed

    private void saveAsociatedMenuItemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_saveAsociatedMenuItemActionPerformed
        main.saveAsociatedOptions(this);
    }//GEN-LAST:event_saveAsociatedMenuItemActionPerformed

    private void jMenuItem1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem1ActionPerformed
        main.showLongerTimeDialog(this);
    }//GEN-LAST:event_jMenuItem1ActionPerformed

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        main.launchUsersFrame(this, main.getCibercafe().getUsersInMaqs());
    }//GEN-LAST:event_jButton1ActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        
        
        try {
            boolean gotIt = false;
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("GTK+".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    gotIt = true;
                    break;
                }
            }
            
            if( !gotIt ){
                for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                    if ("Windows".equals(info.getName())) {
                        javax.swing.UIManager.setLookAndFeel(info.getClassName());
                        gotIt = true;
                        break;
                    }
                }
            }
            
            if( !gotIt ){
                for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                    if ("Nimbus".equals(info.getName())) {
                        javax.swing.UIManager.setLookAndFeel(info.getClassName());
                        break;
                    }
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(MainFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(MainFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(MainFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(MainFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                MainFrame mainFrame = new MainFrame();
                mainFrame.setQueueList(null);
                mainFrame.setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JMenu addServiceMenu;
    private javax.swing.JMenuItem addServiceMenuItem;
    private javax.swing.JButton cancelOpenDialog;
    private javax.swing.JMenuItem closeMenuItem;
    private javax.swing.JMenuItem earningsMenuItem;
    private javax.swing.JButton exitUserButton;
    private javax.swing.JMenu fileMenu;
    private javax.swing.JMenu finacesMenu;
    private javax.swing.JButton finalizeOpenDialog;
    private javax.swing.JButton infoButton;
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JPopupMenu.Separator jSeparator1;
    private javax.swing.JPopupMenu.Separator jSeparator2;
    private java.awt.Label label1;
    private javax.swing.JMenuItem newDayMenuItem;
    private javax.swing.JDialog newInstanceDialog;
    private javax.swing.JMenuItem openMenuItem;
    private javax.swing.JButton processNextButton;
    private javax.swing.JList queueList;
    private javax.swing.JMenuItem regUserMenuItem;
    private javax.swing.JMenuItem saveAsMenuItem;
    private javax.swing.JMenuItem saveAsociatedMenuItem;
    private javax.swing.JMenuItem saveMenuItem;
    private javax.swing.JMenuItem showAllMenuItem;
    private javax.swing.JMenuItem showCurrentUsersMenuItem;
    private javax.swing.JTextField textOpenDialog;
    private javax.swing.JMenu userMenu;
    // End of variables declaration//GEN-END:variables

    public javax.swing.JList getQueueList(){ return queueList; } 
    
    public void setQueueList(List<User> list){
        if( list == null ){
            queueList.setListData(new Object[0]);
            return;
        }
        Object[] newList = new Object[list.size()];
        
        for(int i=0; i < list.size(); i++)
            newList[i] = list.get(i);
        queueList.setListData(newList);
    }
    
    public boolean canEnableProcessNext(){
        Cibercafe cibercafe = main.getCibercafe();
        return !cibercafe.getQueue().isEmpty() && cibercafe.hasAvaliableMaqs();
    }

    public JButton getProcessNextButton() {
        return processNextButton;
    }
}
