/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mypointdemo;

/**
 *
 * @author Zobayer
 */

class MyPoint{

    int x [] = new int[1];
    int y [] = new int[1];
    
    
    MyPoint() {
        x[0] = 0;
        y[0] = 0;
    }
    
    MyPoint(int xx, int yy) {
        x[0] = xx;
        y[0] = yy;
    }
    void currentPosition() {
        System.out.println("Current Position: X axis = " + x[0] + " and Y axis = " + y[0]);
    }
    void moveNewPosition(int xx, int yy) {
        x[0] = xx;
        y[0] = yy;
    }
    double distance(MyPoint temp) {
        return Math.sqrt(Math.pow((x[0] - temp.x[0]), 2) + Math.pow((y[0] - temp.y[0]), 2));
    }
}

public class MyPointDemo {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        MyPoint point1 = new MyPoint(5, 10);
        MyPoint point2 = new MyPoint(15, 20);
        
        point1.currentPosition();
        point2.currentPosition();
        
        System.out.println("Distance is : " + point1.distance(point2));
        
        point1.moveNewPosition(0, 0);
        point2.moveNewPosition(10, 1);
        
        System.out.println("New distance is : " + point1.distance(point2));
    }
    
}
