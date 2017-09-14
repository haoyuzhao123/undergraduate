/*
 * Java Xiaoxueqi - Assignment 3 - Kaoqin
 * Haoyu Zhao
 */

//reuse the code from Assignment 2 Problem 5

import java.io.*;

class Main {
    public static void main(String[] args) {
        try {
        BufferedReader br = new BufferedReader(new FileReader("31.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("31.out")));

        String str;
        str = br.readLine();
        String[] sp = str.split("\\s+");
   
        int n,m;
        n = Integer.parseInt(sp[0]);
        m = Integer.parseInt(sp[1]);

        //input of the students and teachers
        Person[] per = new Person[n];
        for (int i = 0; i < n; i++) {
            str = br.readLine();
            per[i] = new Person(str);
        }

        //record
        for (int i = 0; i < m; i++) {
            str = br.readLine();
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
                out.println(per[i].getInfo());
            }
        }
        br.close();
        out.close();
        }
        catch (FileNotFoundException f) {
            System.out.println("File Not Found");
        }
        catch (IOException i) {
            System.out.println("IO Exception");
        }

    }
}

class Person {
    String category;
    String number;
    String information;
    int count;

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

    String getInfo() {
        return this.information;
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