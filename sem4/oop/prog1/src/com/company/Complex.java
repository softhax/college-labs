package com.company;
import java.util.*;
public class Complex {
    double real;
    double img;

    Complex(double real, double img) {
        this.real = real;
        this.img = img;
    }

    void add(Complex c) {
        this.real += c.real;
        this.img += c.img;
    }

    void subtract(Complex c) {
        this.real -= c.real;
        this.img -= c.img;
    }

    void display() {
        System.out.println("\nThe Complex number is : " + this.real + " + i" + this.img);
    }
}
