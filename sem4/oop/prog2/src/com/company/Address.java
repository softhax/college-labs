package com.company;

public class Address {
    String street;
    String city;
    String state;
    String country;

    Address(String street,String city,String state,String country)
    {
        this.street=street;
        this.city=city;
        this.state=state;
        this.country=country;
    }

    void display()
    {
        System.out.println("Street: "+usn+"\tName:"+name+"\tAddress: "+addr);
    }
}
