/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package experiment;

/**
 *
 * @author Zobayer
 */
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class Uva_10083 {
    public static void main(String [] args) throws IOException {
        int t, a, b;
        BigInteger numerator, denominator, result, minusOne = new BigInteger("1");
        Scanner input = new Scanner(System.in);
        //Scanner input = new Scanner(new FileReader("in.txt"));
        while(input.hasNextInt()) {
            t = input.nextInt();
            a = input.nextInt();
            b = input.nextInt();
            numerator = new BigInteger("" + t);
            denominator = new BigInteger("" + t);

            numerator = numerator.pow(a);
            numerator = numerator.subtract(minusOne);

            denominator = denominator.pow(b);
            denominator = denominator.subtract(minusOne);

            result = numerator.divide(denominator);

            System.out.print("(" + t + "^" + a + "-1)/(" + t + "^" + b + "-1) ");
            if (result.toString().length() > 100) {
                System.out.println("is not an integer with less than 100 digits.");
            }
            else {
                System.out.println(result);
            }
        }
    }
}
