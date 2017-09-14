//File IO
//Haoyu Zhao

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;


class Main {
    public static void main(String[] args) {
        try {
        BufferedReader br = new BufferedReader(new FileReader("exam3.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("exam3.out")));
        String str = br.readLine();

        ArrayList<Util> arr = new ArrayList<Util>();
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            int t = isIn(arr, ch);
            if (t == -1) {
                arr.add(new Util(ch));
            }
            else {
                arr.get(t).a++;
            }
        }
        Collections.sort(arr);
        for (int i = 0; i < arr.size(); i++) {
            out.println(arr.get(i));
        }
        br.close();
        out.close();
    }
    catch (FileNotFoundException e) {}
    catch (IOException e) {}

    }

    public static int isIn(ArrayList<Util> arr, char ch) {
        for (int i = 0; i < arr.size(); i++) {
            Util u = arr.get(i);
            if (u.c == ch) {
                return i;
            }
        }
        return -1;
    }
}

class Util implements Comparable{
    public char c;
    public int a;

    public Util(char x) {
        this.c = x;
        this.a = 1;
    }

    public int compareTo(Object o) {
        Util u = (Util)o;
        if (this.c < u.c) {
            return -1;
        }
        else if (this.c > u.c) {
            return 1;
        }
        else {
            return 0;
        }
    }

    public String toString() {
        return this.c + " " + this.a;
    }
}