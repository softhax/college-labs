package com.company;

public class Student {
    String usn;
    String name;
    Address addr;

   Student(String usn,String name,String addr)
   {
        this.usn=usn;
        this.name=name;
        this.addr=addr;
   }

   void display()
   {
       System.out.println("USN: "+usn+"\tName:"+name+"\tAddress: "+addr);
   }

}

