/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package innerclassdemo;

/**
 *
 * @author Zobayer
 */

class Outer {
    static int outer_x = 100;
    
    Inner inner = new Inner();
    //inner.display();
    static class Inner {
        public void display() {
            System.out.println("Display : outer_x = " + outer_x);
        }
    }
}
public class InnerClassDemo {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        //Outer outer = new Outer();
        //outer.test();
        Outer.Inner ns = new Outer.Inner();
        ns.display();
        //System.out nm = new System.out();
    }
    
}
