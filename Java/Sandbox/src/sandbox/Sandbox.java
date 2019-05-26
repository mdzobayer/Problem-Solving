/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package sandbox;
import java.util.Date;
/**
 *
 * @author Zobayer
 */
enum FreshJuiceSize {SMALL, MEDIUM, LARGE };
class FreshJuice {
    
    FreshJuiceSize size;
}

class Outer {
    int num;
    
    public class Inner {
        public void print() {
            System.out.println("This is and inner class");
        }
    }
    public void displayInner() {
        Inner inner = new Inner();
        inner.print();
    }
}


public class Sandbox {

    /**
     * @param args the command line arguments
     */
    
    public Sandbox(String st) {
        System.out.println("Passed name is : " + st);
    }
    
    public static void main(String[] args) {
        // TODO code application logic here
        
        FreshJuice juice = new FreshJuice();
        juice.size = FreshJuiceSize.MEDIUM;
        System.out.println("Size: " + juice.size);
        Sandbox sb = new Sandbox("Hello World!");
        Date date = new Date();
        System.out.println(date.toString());
        Outer outer = new Outer();
        //Outer.Inner OuIn = new Outer.Inner();
    }
    int change(int x) {
        x = 12;
        return x;
       // byte bt;
    }
    
}
