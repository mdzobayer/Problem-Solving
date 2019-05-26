/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package firstclasstest;

/**
 *
 * @author Zobayer
 */

class Account {
    private String account_id;
    private String account_name;
    private double amount;
    
    Account() {
        account_id = "";
        account_name = "";
        amount = 0.0;
    }
    Account(String id, String name, double a) {
        account_id = id;
        account_name = name;
        amount = a;
    }
    void deposit(double a) {
        amount = amount + a;
    }
    double currentBalance() {
        return amount;
    }
    double withdraw(double a) {
        if (a > amount) {
            System.out.println("In sufficient Balance");
            return (0.0);
        }
        else {
            amount = amount - a;
            return a;
        }
    }
}
public class FirstClassTest {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Account ac = new Account("C-12", "Arif", 110.0);
        
        // Now check current balance
        System.out.println("Current balance is " + ac.currentBalance());
        
        // withdraw Some (80) money
        System.out.println("Withdraw money is " + ac.withdraw(80.0));
        
        // again check current balance
        System.out.println("Current balance is " + ac.currentBalance());
        
        // Now deposit some( money
        ac.deposit(20.0);
        
        // again check current balance
        System.out.println("Current balance is " + ac.currentBalance());
        
        // now try to withdraw some money larger than save money(amount)
        System.out.println("Withdraw money is " + ac.withdraw(80.0));
    }
    
}
