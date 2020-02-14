package com.company;

import java.util.Scanner;

public class College {
    String name;
    Address addr;

    College(String name, Address addr) {
        this.name = name;
        this.addr = addr;
    }
    College(){}
    void input()
    {
        Scanner s5 = new Scanner(System.in);
        name=s5.next();
        addr = new Address();
        addr.input();
    }
    void display()
    {
        System.out.println("\nName:"+name+"\tAddress: "+addr);
    }
}
