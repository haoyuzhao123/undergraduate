/*
 * Java Xiaoxueqi - Assignment 2 - Counts 
 * Haoyu Zhao
 */

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str;
        str = sc.nextLine();
        Scanner scp = new Scanner(str);       
        int n,m;
        n = scp.nextInt();
        m = scp.nextInt();
        //input of the students and teachers
        Person[] per = new Person[n];
        for (int i = 0; i < n; i++) {
            str = sc.nextLine();
            per[i] = new Person(str);
        }

        //record
        for (int i = 0; i < m; i++) {
            str = sc.nextLine();
            String[] s = str.split("\\s+");
            for (int j = 0; j < n; j++) {
                Person p = per[j];
                if (p.getCate().equals(s[0]) && p.getNum().equals(s[1])) {
                    p.record();
                }
            }
        }

        int maxNum = 0;
        for (int i = 0; i < n; i++) {
            if (per[i].getTime() > maxNum) {
                maxNum = per[i].getTime();
            }
        }

        for (int i = 0; i < n; i++) {
            if (per[i].getTime() == maxNum) {
                per[i].printInfo();
            }
        }

    }
}

class Person {
    private String category;
    private String number;
    private String information;
    private int count;

    Person(String str) {
        this.count = 0;
        this.information = str;
        String[] stra = str.split("\\s+");
        if (stra[0].equals("Teacher")) {
            this.category = "T";
        }
        else {
            this.category = "S";
        }

        this.number = stra[1];
    }

    void printInfo() {
        System.out.println(this.information);
    }

    void record() {
        this.count += 1;
    }

    String getCate() {
        return this.category;
    }

    String getNum() {
        return this.number;
    }

    int getTime() {
        return this.count;
    }
}