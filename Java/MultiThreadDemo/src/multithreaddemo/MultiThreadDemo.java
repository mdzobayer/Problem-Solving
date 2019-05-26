/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package multithreaddemo;

/**
 *
 * @author Zobayer
 */



public class MultiThreadDemo {
    public static void main(String [] args) {
        new NewThread("One");
        new NewThread("Two");
        new NewThread("Three");

        try {
            // Wait for other threads to end
            Thread.sleep(10000);
        }
        catch (InterruptedException e) {
            System.out.println("Main thread Interrupted.");
        }
        System.out.println("Main thread exiting.");
    };
};
