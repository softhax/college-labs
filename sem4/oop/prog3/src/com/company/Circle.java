package com.company;

public class Circle {
    private double radius;
    private String colour;

    Circle()
    {
        radius=0.0;
        colour="Blue";
    }

    Circle(double r)
    {
        radius=r;
        colour="Blue";

    }

    Circle(double r,String c)
    {
        radius=r;
        colour=c;
    }

    String getColour()
    {
        return colour;
    }

    double getRadius()
    {
        return radius;
    }

    double getArea()
    {
        return (Math.PI * radius * radius);
    }

    void display()
    {
        System.out.println("Radius:" + this.getRadius() + "\tColour: "+ this.getColour() + "\tArea: "+this.getArea());
    }
}