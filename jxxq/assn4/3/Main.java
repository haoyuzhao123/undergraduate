/*
 * Java Xiaoxueqi - Assignment 4 - html
 * Haoyu Zhao
 */

import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String html = sc.nextLine();
        Pattern p = Pattern.compile("<[^>]*?>");
        Matcher m = p.matcher(html);
        String res = m.replaceAll("");
        System.out.println(res);
    }
}