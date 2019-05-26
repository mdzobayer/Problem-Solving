/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package helper;

import helper.Person;

/**
 *
 * @author Zobayer
 */
public class Employee extends Person{
    public int rate;
    public int totalDay;
    
    public Employee(){
        super();
        rate = 0;
        totalDay = 0;
    }
    public Employee(String n, String id, int ag, int r, int d) {
        super(n, id, ag);
        rate = r;
        totalDay = d;
        setTest(115);
    }
}
