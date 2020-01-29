package com.company;
import com.company.Complex;
import java.util.*;


public class Main {

    public static void main(String[] args) {
    Complex c1 = new Complex(2, 4);    //Using the constructor to initialize
    Scanner s1 = new Scanner(System.in);
    Complex c2 = new Complex(s1.nextInt(), s1.nextInt());
    c1.display();
    c2.display();
    c2.add(c1);
    c2.display();

    }
}
