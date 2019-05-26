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
public class TestIface {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Callback c = new Client();
        c.callback(42);
        
        Client cc = new Client();
        cc.nonIfaceMeth();
    }
    
}
