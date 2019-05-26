/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Again;

/**
 *
 * @author Zobayer
 */
public class Demo {
    public static void main(String [] args) {
        try{
            ChatClient c = new ChatClient("hello");
            c.setVisible(true);
        }
        catch(Exception e) {
            
        }
    }
}
