/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package helper;

/**
 *
 * @author Zobayer
 */
public class Person {
    public String name;
    public String identi;
    public int age;
    public int test;
    
    public Person() {
        name = "";
        identi = "";
        age = 0;
    }
    public Person(String n, String id, int a) {
        name = n;
        identi = id;
        age = a;
    }
    public void display(){
        System.out.println("Name is : " + name);
        System.out.println("Identity is : " + identi);
        System.out.println("Age is : " + age);
    }
    
    public void setTest(int n) {
        test = n;
    }
    public int getTest() {
        return test;
    }
}
