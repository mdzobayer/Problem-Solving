/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package finalkeyword;

/**
 *
 * @author Zobayer
 */
public class FinalKeyword {

    /**
     * @param args the command line arguments
     */
    static final double pi = 3.1415;
    
    public static void main(String[] args) {
        // TODO code application logic here
        
        // If i want to modify pi is now allow.
        //pi = 52.12;
        
        double radius = 12;
        double circomfarence;
        
        circomfarence = 2 * pi * radius;
        
        System.out.println("Circomference of the circle is " + circomfarence);
        
    }
    
}
