/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package runnable;

/**
 *
 * @author Zobayer
 */
public class SecondThread implements Runnable {
    Thread t;
    SecondThread() {
        t = new Thread(this,"Demo Thread");
        System.out.println("Child thread: " + t);
    }
    public void run() {
        try {
            for (int i = 5; i > 0; --i) {
                System.out.println("Child Thread: " + i);
                Thread.sleep(500);
            }
        }
        catch(InterruptedException e) {
            System.out.println("Child Interrupted");
        }
        System.out.println("Exiting child thread.");
    }
    
}











