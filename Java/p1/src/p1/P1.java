/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package p1;

/**
 *
 * @author Zobayer
 */
import java.lang.reflect.InvocationTargetException;
import java.lang.Class;
import p2.*;
import p3.testP3;
import test.*;


public class P1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws ClassNotFoundException, NoSuchMethodException, IllegalAccessException, IllegalArgumentException, InvocationTargetException {
        // TODO code application logic here
        
        protection pObj = new protection();
        System.out.println(pObj.word);
        derived dObj = new derived();
        System.out.println(dObj.word);
        
        derivedP2 dp2Obj = new derivedP2();
        System.out.println(dp2Obj.getWord());
        
        test testObj = new test();
        
        testP3 p3Obj = new testP3();
        System.out.println(p3Obj.word);
        
        Employee emp = new Employee();
        System.out.println(emp.getName());
        
        Manager mn = new Manager();
        System.out.println(mn.getName());
        
        /// Reflection
        //Class.forName("test12").getMethod("getName").invoke(null);
        String MyClassName = "test12";
        Class c = MyClassName.getClass();
        String name = c.getName();
        System.out.println(name);
    }
    
}
