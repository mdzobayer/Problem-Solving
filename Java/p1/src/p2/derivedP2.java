/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package p2;

/**
 *
 * @author Zobayer
 */
import p1.protection;

public class derivedP2 extends protection{
    public derivedP2() {
        super("I am from p2 package");
    }
    public String getWord() {
        return returnWord();
    }
}
