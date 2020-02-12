
package com.company;

public class Main {

    public static void main(String[] args) {

        Circle c1=new Circle(1,"red");
        Circle c2=new Circle(2);
        Cylinder x1=new Cylinder(3,1);
        Cylinder x2=new Cylinder(3,1,"Blue");
        c1.display();
        c2.display();
        System.out.println();
        x1.display();
        x2.display();
        System.out.println((x1.equals(x2))?"The two cylinders are equal":"The cylinders are different");


    }
}