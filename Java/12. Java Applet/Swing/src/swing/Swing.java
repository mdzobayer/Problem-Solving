/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package swing;

/**
 *
 * @author Zobayer
 */

//package com.bitguru.org.swing;

import javax.swing.*;
import java.awt.*;
public class Swing {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        JLabel greeting = new JLabel ("Hello, World", JLabel.CENTER);
        
        greeting.setFont(new Font("serif", Font.PLAIN, 32));
        greeting.setForeground(Color.RED);
        JFrame frame = new JFrame("Important Message");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().add(greeting);
        frame.setSize(480, 256);
        frame.setVisible(true);
    }
    
}
