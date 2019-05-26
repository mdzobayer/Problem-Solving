/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package imagelabel;

import java.awt.Color;
import java.awt.Font;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingUtilities;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import java.net.URL;

/**
 *
 * @author Zobayer
 */
public class ImageLabel {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        /// Using Lamda expression
        //SwingUtilities.invokeLater(() -> new HelloWorld().startup());
        
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new ImageLabel().startup();
            }
        });
    }
    public void startup() {
        
        Icon icon = new ImageIcon("C:\\Users\\Zobayer\\Desktop\\Passion.PNG");
        
        //Icon icon = new ImageIcon( new URL("www.host.com/image.jpg"));
        
        JLabel  greeting = new JLabel(icon, JLabel.CENTER);
        greeting.setFont(new Font("serif", Font.PLAIN, 32));
        greeting.setForeground(Color.RED);
        
        JFrame frame = new JFrame("Important Message");
        frame.getContentPane().add(greeting);
        frame.setSize(720, 720);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
    
}
