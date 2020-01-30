package com.company;

public class Snake implements TiredAnimal{

    String q;
    Snake(String q)
    {
        this.q=q;
    }
    public void eat() {
        System.out.println("Snake eats");
    }

    public void sleeps()
    {
        System.out.println("Snake sleeps");
    }
}
