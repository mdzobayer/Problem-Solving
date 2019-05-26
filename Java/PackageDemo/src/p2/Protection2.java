/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package p2;

/**
 *
 * @author STUDENT
 */
class Protection2 extends p1.Protection{
    public Protection2() {
        System.out.println("Derived other package Constructor");
        
        //System.out.println("n_pri = " + n_pri);
        
        System.out.println("n_pro = " + n_pro);
        System.out.println("n_pub = " + n_pub);
    }
}
