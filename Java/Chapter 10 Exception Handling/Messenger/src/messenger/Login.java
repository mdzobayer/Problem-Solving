/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package messenger;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.*;
import java.net.*;
import javax.swing.*;

/**
 *
 * @author Zobayer
 */
public class Login {
    public static void main(String [] args) throws IOException, UnknownHostException{
        //ChatClient client = new ChatClient("Sujit");
        final JFrame login = new JFrame("Login");
        JPanel panel = new JPanel();
        JTextField loginName = new JTextField(20);
        JButton enter = new JButton("Login");
        
        login.setSize(300, 100);
        panel.add(loginName);
        panel.add(enter);
        login.add(panel);
        login.setVisible(true);
        login.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        enter.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e) {
                try {
                    ChatClient client = new ChatClient(loginName.getText());
                    login.setVisible(false);
                    login.dispose();
                }
                catch(UnknownHostException e1){
                    e1.printStackTrace();
                }
                catch(IOException e1) {
                    e1.printStackTrace();
                }
            }
        });
        
        loginName.addKeyListener(new KeyListener(){
            @Override
            public void keyTyped(KeyEvent e) {
                //To change body of generated methods, choose Tools | Templates.
            }

            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                    try{
                        ChatClient client = new ChatClient(loginName.getText());
                        login.setVisible(false);
                        login.dispose();
                    }
                    catch(UnknownHostException e1) {
                        e1.printStackTrace(); 
                    }
                    catch(IOException e1) {
                        e1.printStackTrace();
                    }
                }
            }

            @Override
            public void keyReleased(KeyEvent e) {
                //To change body of generated methods, choose Tools | Templates.
            }
            
        });
    }
}
