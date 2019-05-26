/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package experiment;

/**
 *
 * @author Zobayer
 */
import java.math.*;

public class main {
    
    public static void main(String [] args) {
        BigInteger bi1, bi2, bi3, bi4;
        
        bi1 = new BigInteger("123");
        bi2 = new BigInteger("-123");
        
        bi3 = bi1.abs();
        bi4 = bi2.abs();
        System.out.println(bi3.compareTo(bi4));
        System.out.println(bi3);
        System.out.println(bi4);
        
        bi3 = bi3.add(bi4);
        System.out.println(bi3);
        System.out.println(bi3.toString().length());
        System.out.println(bi3.subtract(bi1));
        System.out.println(bi3.divide(bi1));
        System.out.println(bi3.multiply(bi1));
        System.out.println(bi1.max(bi3));
        System.out.println(bi1.min(bi3));
        System.out.println(bi3.mod(bi1));
        System.out.println(bi3.remainder(bi1));
        System.out.println(bi3.compareTo(bi1));
    }
    
    
}
