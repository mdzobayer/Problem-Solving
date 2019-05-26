/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package p1;

/**
 *
 * @author STUDENT
 */
public class SamePackage {
    public SamePackage() {
        Protection p = new Protection();
        System.out.println("Same package Constructor");
        System.out.println("n = " + p.n);
        
        //System.out.println("n_pri = " + p.n_pri);
        
        System.out.println("n_pro = " + p.n_pro);
        System.out.println("n_pub = " + p.n_pub);
                
    }
}
