package com.company;

import java.util.Scanner;

public class Address {
    String street;
    String city;
    String state;
    String country;

    Address(String street, String city, String state, String country) {
        this.street = street;
        this.city = city;
        this.state = state;
        this.country = country;
    }
    Address(){}

    void input() {
        Scanner s4 = new Scanner(System.in);
        street = s4.next();
        city = s4.next();
        state = s4.next();
        country = s4.next();

    }

    void display() {
        System.out.println("Street: " + street + "\tCity:" + city + "\tState: " + state+ "\tCountry: " + country);
    }
}
