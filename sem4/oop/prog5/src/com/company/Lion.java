package com.company;

public class Lion implements Animal{
    String p;
    Lion(String p)
    {
        this.p=p;
    }
    public void eat() {
        System.out.println("Lion eats");
    }
}
