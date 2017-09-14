/*
 * Java Xiaoxueqi - Assignment 4 - Date
 * Haoyu Zhao
 */

import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        Pattern p = Pattern.compile("\\d{4}-\\d{2}-\\d{2}");
        Matcher m = p.matcher(line);
        int count = 0;
        int idx = 0;
        while (m.find(idx)) {
            String s = m.group();
            //System.out.println("matches: " + s);
            idx = m.start() + 1;
            if (isLegalDay(s)) {
                System.out.println(s);
                count++;
            }
        }
        if (count == 0) {
            System.out.println("NotMatch");
        }
    }

    public static boolean isLegalDay(String str) {
        String y = str.substring(0,4);
        String m = str.substring(5,7);
        String d = str.substring(8,10);
        int year = Integer.parseInt(y);
        int month = Integer.parseInt(m);
        int day = Integer.parseInt(d);
        if (year < 1990 || year >2017) {
            return false;
        }
        boolean res = true;
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (day > 31 || day < 1)
                    res = false;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (day > 30 || day < 1)
                    res = false;
                break;
            case 2:
                if (day > 28 || day < 1)
                    res = false;
                    break;
            default:
                res = false;
                break;
        }
        return res;
    }
}