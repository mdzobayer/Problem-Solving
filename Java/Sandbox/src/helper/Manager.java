/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package helper;

import helper.Employee;

/**
 *
 * @author Zobayer
 */
public class Manager extends Employee {
    public int extraFacilityAmount;
    
    public Manager() {
        super();
        extraFacilityAmount = 0;
    }
    public Manager(String n, String id, int ag, int r, int d, int ex) {
        super(n, id, ag, r, d);
        extraFacilityAmount = ex;
    }
}
