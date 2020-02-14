package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        System.out.println("Enter the value of n:");
        int n;
        Scanner s1 = new Scanner(System.in);
        n = s1.nextInt();
        int i;
        Student s[] = new Student[n];
        College c[] = new College[n];
        Employee e[] = new Employee[n];
        for (i = 0; i < n; i++) {
            s[i] = new Student();
            c[i] = new College();
            e[i] = new Employee();
            s[i].input();
            c[i].input();
            e[i].input();
        }

        System.out.println("The entered details are : \n");

        for (i = 0; i < n; i++) {
            s[i].display();
            c[i].display();
            e[i].display();
        }
    }
}
