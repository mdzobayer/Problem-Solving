/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package helloworld;

/**
 *
 * @author Zobayer
 */

import experiment.test;
import javax.swing.*;
import java.awt.*;

public class HelloWorld {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        /// Using Lamda expression
        //SwingUtilities.invokeLater(() -> new HelloWorld().startup());
        
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new HelloWorld().startup();
            }
        });
    }
    public void startup() {
        /*
        JLabel  greeting = new JLabel("Hello, world!", JLabel.CENTER);
        greeting.setFont(new Font("serif", Font.PLAIN, 32));
        greeting.setForeground(Color.RED);
        
        JFrame frame = new JFrame("Important Message");
        frame.getContentPane().add(greeting);
        frame.setSize(240, 160);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
*/
        test object = new test();
        System.out.println("Name is " + object.getName());
    }
    
}
