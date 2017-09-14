/*
 * Java Xiaoxueqi - Assignment 4 - Addition
 * Haoyu Zhao
 */

import java.util.Scanner;

import java.util.ListIterator;

import java.util.LinkedList;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList<Integer> n1 = new LinkedList<Integer>();
        LinkedList<Integer> n2 = new LinkedList<Integer>();
        LinkedList<Integer> res;
        String line;
        line = sc.nextLine();
        String[] arr = line.split("\\s+");
        for (int i = 0; i < arr.length; i++) {
            n1.addFirst(Integer.parseInt(arr[i]));
        }
        line = sc.nextLine();
        arr = line.split("\\s+");
        for (int i = 0; i < arr.length; i++) {
            n2.addFirst(new Integer(Integer.parseInt(arr[i])));
        }
        res = addition(n1, n2);
        ListIterator<Integer> itr = res.listIterator();
        while(itr.hasNext()) {
            System.out.print(itr.next());
            if (itr.hasNext()) {
                System.out.print(" ");
            }
        }
    }

    public static LinkedList<Integer> addition(LinkedList<Integer> n1, LinkedList<Integer> n2) {
        ListIterator<Integer> itr1 = n1.listIterator();
        ListIterator<Integer> itr2 = n2.listIterator();
        LinkedList<Integer> res = new LinkedList<Integer>();
        int c = 0;
        while(true) {
            int a;
            int b;
            if (itr1.hasNext()) {
                a = itr1.next().intValue();
                b = 0;
                if (itr2.hasNext()) {
                    b = itr2.next().intValue();
                }
                res.push(new Integer((a+b+c)%10));
                c = (a + b + c) / 10;
            }
            else {
                a = 0;
                b = 0;
                if (itr2.hasNext()) {
                    b = itr2.next().intValue();
                }
                else {
                    if (c == 0)
                        break;
                }
                res.push(new Integer((a + b + c)%10));
                c = (a + b + c) / 10;
            }
        }
        return res;
    }

    public static LinkedList<Integer> multi(LinkedList<Integer> n1, int x) {
        LinkedList<Integer> res = new LinkedList<Integer>();
        ListIterator<Integer> itr1 = n1.listIterator();
        if (x == 0) {
            res.addFirst(new Integer(0));
            return res;
        }
        else if (res.getFirst().intValue() == 0) {
            res.addFirst(new Integer(0));
            return res;
        }
        else {
            int c = 0;
            while(true) {
                int a;
                if (itr1.hasNext()) {
                    a = itr1.next().intValue();
                    res.push(new Integer((a*x+c)%10));
                    c = (a*x + c) / 10;
                }
                else {
                    if (c == 0)
                        break;
                    res.push(new Integer(c));
                    c = 0;
                }
            }
        }
    }
}

