/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package runnable;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Zobayer
 */
public class ThreadDemo {
    public static void main(String [] args) {
        //Thread ct = Thread.currentThread();
        SecondThread st = new SecondThread();
        st.t.start();
        
        try {
            st.t.join();
        } catch (InterruptedException ex) {
            System.out.println("Joining problem");
        }
        
        for (int i = 0; i < 5; ++i) {
            System.out.println("I am main " + i);
            try {
                Thread.sleep(100);
            } catch (InterruptedException ex) {
                
            }
        }
        System.out.println("Aftar waiting ");
    }
}











