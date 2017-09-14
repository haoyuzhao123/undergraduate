/*
 * Java Xiaoxueqi - Assignment 3 - Seaerch File
 * Haoyu Zhao
 */

import java.util.Scanner;
import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String keyword = sc.nextLine();
        keyword = keyword.toLowerCase();
        List<String> vec = new ArrayList<String>();

        try {
            File f = new File("/usr/bin");
            String[] files = f.list();
            for (int i = 0; i < files.length; i++) {
                vec.add(files[i]);
            }
        }
        catch (Exception e) {
            System.out.println("Exception happens.");
        }

        Collections.sort(vec);
        for (int i = 0; i < vec.size(); i++) {
            if (isContains(vec.get(i), keyword)) {
                System.out.println(vec.get(i));
            }
        }
    }

    public static boolean isContains(String str, String key) {
        if (str.toLowerCase().indexOf(key) == -1) {
            return false;
        }
        return true;
    }
}