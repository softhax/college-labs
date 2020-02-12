package com.company;
import java.util.*;
public class Complex {
    double real;
    double img;

    Complex(){
        this.real = 0;
        this.img = 0;
    }
    Complex(double real, double img) {
        this.real = real;
        this.img = img;
    }

    Complex add(Complex c1,Complex c2) {
        return (new Complex(c1.real+c2.real,c1.img+c2.img));
    }

    Complex subtract(Complex c1, Complex c2) {
        return (new Complex(c1.real-c2.real,c1.img-c2.img));
    }

    void display() {
        System.out.print(this.real + " + i" + this.img+"\t");
    }
}
