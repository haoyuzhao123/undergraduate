// Multiplication
// Haoyu Zhao

import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList<Integer> n1 = new LinkedList<Integer>();
        LinkedList<Integer> n2 = new LinkedList<Integer>();
        LinkedList<Integer> res;
        String line;
        line = sc.nextLine();
        String[] arr = line.split("\\s+");
        if (arr.length == 1 && arr[0].equals("0")) {
            System.out.println(0);
            return;
        }
        for (int i = 0; i < arr.length; i++) {
            n1.addFirst(Integer.parseInt(arr[i]));
        }
        line = sc.nextLine();
        arr = line.split("\\s+");
        if (arr.length == 1 && arr[0].equals("0")) {
            System.out.println(0);
            return;
        }
        for (int i = 0; i < arr.length; i++) {
            n2.addFirst(new Integer(Integer.parseInt(arr[i])));
        }

        res = multiplication(n1, n2);
        //res = multi(n1, 5, 4);
        //res = addition(n1, n2);
        ListIterator<Integer> itr = res.listIterator();
        LinkedList<Integer> newres = new LinkedList<Integer>();
        while(itr.hasNext()) {
            newres.addFirst(itr.next());
        }
        itr = newres.listIterator();
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
                res.addLast(new Integer((a+b+c)%10));
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
                res.addLast(new Integer((a + b + c)%10));
                c = (a + b + c) / 10;
            }
        }
        return res;
    }

    public static LinkedList<Integer> multi(LinkedList<Integer> n1, int x, int count) {
        LinkedList<Integer> res = new LinkedList<Integer>();
        ListIterator<Integer> itr1 = n1.listIterator();
        if (x == 0) {
            res.addLast(new Integer(0));
            return res;
        }
        else {
            int c = 0;
            while(true) {
                int a;
                if (itr1.hasNext()) {
                    a = itr1.next().intValue();
                    res.addLast(new Integer((a*x+c)%10));
                    c = (a*x + c) / 10;
                }
                else {
                    if (c == 0)
                        break;
                    res.addLast(new Integer(c));
                    c = 0;
                }
            }
        }
        for (int i = 0; i < count; i++) {
            res.addFirst(new Integer(0));
        }
        return res;
    }

    public static LinkedList<Integer> multiplication(LinkedList<Integer> n1, LinkedList<Integer> n2) {
        int count = 0;
        LinkedList<Integer> res = new LinkedList<Integer>();
        ListIterator<Integer> itr1 = n1.listIterator();
        while(true) {
            if (itr1.hasNext()) {
                int x = itr1.next().intValue();
                LinkedList<Integer> temp = multi(n2, x, count);
                count++;
                res = addition(res, temp);
            }
            else {
                break;
            }
        }
        return res;
    }
}