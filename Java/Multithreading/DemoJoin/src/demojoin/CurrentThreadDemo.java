/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package demojoin;

/**
 *
 * @author Zobayer
 */
public class CurrentThreadDemo {
    public static void main(String [] args) {
        Thread t = Thread.currentThread();
        
        System.out.println("Current thread: " + t);
        
        // Change the name of the thread
        t.setName("My thread");
        System.out.println("After changing name: " + t);
        try{
            for(int n = 5; n > 0; --n) {
                System.out.println(n);
                Thread.sleep(1000);
            }
        }
        catch(InterruptedException e) {
            System.out.println("Main thread interrupted");
        }
    }
}





















