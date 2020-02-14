package com.company;

import java.util.Scanner;

public class Employee {
    String empid;
    String name;
    Address addr;

    Employee(String empid, String name, Address addr) {
        this.empid = empid;
        this.name = name;
        this.addr = addr;
    }
    Employee(){}
    void input()
    {
        Scanner s2 = new Scanner(System.in);
        empid=s2.next();
        name=s2.next();
        addr = new Address();
        addr.input();
    }
    void display() {
        System.out.println("\nEmployeeID: " + empid + "\tName:" + name + "\tAddress: " + addr);
    }
}
