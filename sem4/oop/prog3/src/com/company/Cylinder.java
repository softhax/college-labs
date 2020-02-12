package com.company;

public class Cylinder extends Circle{
    private double height;

    Cylinder()
    {
        super();
        this.height=1;
    }

    Cylinder(double h,double r)
    {
        super(r);
        height=h;
    }

    Cylinder(double h,double r,String c)
    {
        super(r,c);
        height=h;
    }

    double getHeight()
    {
        return height;
    }

    double getArea()
    {
        return (2*Math.PI*(super.getRadius())*height) + (Math.PI*(super.getArea()));
    }

    double getVolume()
    {
        return Math.PI*(super.getRadius())*(super.getRadius())*height;
    }

    void display()
    {
        System.out.println("Radius:" + this.getRadius() + " Height " + this.getHeight() + "\tColour: "+ this.getColour() + "\tArea: "+this.getArea()+"\tVolume: "+this.getVolume());
    }

    boolean equals(Cylinder c)
    {
        return ((this.getHeight()==c.getHeight()) && (this.getRadius()==c.getRadius())  && (this.getArea()==c.getArea()) && (this.getColour()==c.getColour()) && (this.getVolume()==c.getVolume())  );
    }

}