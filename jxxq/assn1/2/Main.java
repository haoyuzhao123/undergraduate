/*
 * Java Xiaoxueqi - Assignment 1 - Sort
 * Haoyu Zhao
*/

import java.util.Scanner;
import java.util.Collections;
import java.util.ArrayList;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Scanner scp = new Scanner(sc.nextLine());
        ArrayList list = new ArrayList();
        while (scp.hasNextInt()) {
            int in = scp.nextInt();
            list.add(new Integer(in));
        }
        Collections.sort(list);
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i).toString() + " ");
        }
        System.out.print("\r\n");
    }
}