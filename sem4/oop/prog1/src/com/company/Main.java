package com.company;

import com.company.Complex;

import java.util.*;


public class Main {

    public static void main(String[] args) {

        Scanner s1 = new Scanner(System.in);
        Complex c1 = new Complex(2, 4);    //Using the constructor to initialize
        Complex c2 = new Complex(s1.nextDouble(), s1.nextDouble());
        Complex c3 = new Complex();
        System.out.println("Initially :\nc1\t\t\tc2\t\t\tc3");
        c1.display();c2.display();c3.display();
        System.out.println("After addition :\nc1\t\t\tc2\t\t\tc3");
        c3 = c3.add(c1,c2);
        c1.display();c2.display();c3.display();
        System.out.println("After Subtraction :\nc1\t\t\tc2\t\t\tc3");
        c3 = c3.subtract(c1,c2);
        c1.display();c2.display();c3.display();


    }
}
