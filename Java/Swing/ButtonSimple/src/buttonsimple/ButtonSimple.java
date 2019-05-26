/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package buttonsimple;

/**
 *
 * @author Zobayer
 */
import javax.swing.*;
import java.awt.*;

public class ButtonSimple {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        SwingUtilities.invokeLater( () -> new ButtonSimple().startup());
    }
    public void startup() {
        JLabel message = new JLabel("Hello, World", JLabel.CENTER);
        
        JButton button1 = new JButton("Button One");
        JButton button2 = new JButton("Button Two");
        JButton button3 = new JButton("Button Three");
        
        button1.setFont(new Font("serif", Font.ITALIC, 16));
        button1.setForeground(Color.red);
        
        button2.setEnabled(false);
        //button3.setBorder(BorderFactory.createRaisedBevelBorder()); // Don't Do this
        
        button1.setPreferredSize(button3.getPreferredSize());
        button2.setPreferredSize(button3.getPreferredSize());
        
        button1.setMnemonic('o');
        button1.setDisplayedMnemonicIndex(7);
        button2.setMnemonic('t');
        button2.setDisplayedMnemonicIndex(7);
        button3.setMnemonic('h');
        
        
        JFrame frame = new JFrame("Passing Matters");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setLayout(new FlowLayout());
        
        frame.getContentPane().add(message);
        frame.getContentPane().add(button1);
        frame.getContentPane().add(button2);
        frame.getContentPane().add(button3);
        
        /// Setting Default Button
        frame.getRootPane().setDefaultButton(button3);
        
        frame.setSize(200, 240);
        frame.setVisible(true);
    }
}
