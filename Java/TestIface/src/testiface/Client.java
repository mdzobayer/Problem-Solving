/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testiface;

/**
 *
 * @author Zobayer
 */
public class Client implements Callback {
    public void callback(int p) {
        System.out.println("callback called with " + p);
    }
    public void nonIfaceMeth() {
        System.out.println("Classes that implements interfaces " +
                "may also define other member, too.");
    }
}
