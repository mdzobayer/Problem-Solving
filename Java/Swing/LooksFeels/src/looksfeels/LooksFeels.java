/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package looksfeels;

/**
 *
 * @author Zobayer
 */
import javax.swing.*;
import java.awt.*;

public class LooksFeels {

    /**
     * @param args the command line arguments
     */
    
    public void startup() {
        JTabbedPane tabp = new JTabbedPane();
        tabp.add("one", new JTextField("once", 16));
        tabp.add("two", new JTextField("twice", 16));
        
        JComboBox<String> combo = new JComboBox<String> (new String [] {"one", "two", "three"});
        JButton button = new JButton("do it");
        
        JScrollPane scroll = new JScrollPane(new JTextArea(UIManager.getLookAndFeel().toString(), 3, 16));
        
        JSlider slider = new JSlider();
        
        JFrame frame = new JFrame(UIManager.getLookAndFeel().getName());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        frame.getContentPane().setLayout(new FlowLayout(FlowLayout.CENTER, 16, 16));
        frame.getContentPane().add(tabp);
        frame.getContentPane().add(combo);
        frame.getContentPane().add(button);
        frame.getContentPane().add(button);
        frame.getContentPane().add(scroll);
        frame.getContentPane().add(slider);
        frame.setSize(240, 300);
        frame.setVisible(true);
    }
    
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        for (UIManager.LookAndFeelInfo lafi : UIManager.getInstalledLookAndFeels()) {
            System.out.println(lafi);
        }
        
//        UIManager.setLookAndFeel("javax.swing.plaf.metal.MetalLookAndFeel");
//        UIManager.setLookAndFeel(UIManager.getCrossPlatformLookAndFeelClassName()); //also metal
//        UIManager.setLookAndFeel("javax.swing.plaf.nimbus.NimbusLookAndFeel");
//        UIManager.setLookAndFeel("com.sun.java.swing.plaf.motif.MotifLookAndFeel");
//        UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
//        UIManager.setLookAndFeel("com.apple.laf.AquaLookAndFeel");
//        UIManager.setLookAndFeel("com.sun.java.swing.plaf.gtk.GTKLookAndFeel");
        
        SwingUtilities.invokeLater( () -> new LooksFeels().startup() );
    }
    
}




