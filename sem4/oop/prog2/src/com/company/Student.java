package com.company;

import java.util.Scanner;

public class Student {
    String usn;
    String name;
    Address addr;

    Student(String usn, String name, Address addr) {
        this.usn = usn;
        this.name = name;
        this.addr = addr;
    }

    void input()
    {
        Scanner s3 = new Scanner(System.in);
        usn=s3.next();
        name=s3.next();
        addr.input();
    }
    void display() {
        System.out.println("USN: " + usn + "\tName:" + name + "\tAddress: " + addr);
    }

}

