package OnlineAdda;

import helper.Manager;
import helper.Employee;
import helper.Person;

class Experiment {
    
    public static void main(String[] args) {
    // TODO code application logic here
        
        Person p1 = new Person("Zobayer", "CSE059-07156", 20);
        
        Employee emp1 = new Employee("Sujit", "Cse454", 22, 10, 30);
        
        Manager mn1 = new Manager("Al-Amin", "IT454", 35, 18, 30, 100);
        
        p1.display();
        emp1.display();
        mn1.display();
        
    }
}
