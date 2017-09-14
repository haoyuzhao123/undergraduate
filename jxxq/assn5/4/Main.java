/*
 * Java Xiaoxueqi - Assignment 5 - Host Reader
 * Haoyu Zhao
 */

import java.util.Collections;
import java.io.*;
import java.net.*;
import java.util.Scanner;
import java.util.regex.*;
import java.util.Set;
import java.util.TreeSet;
import java.util.Iterator;
import java.util.ArrayList;
import java.util.ListIterator;
import java.util.Collections;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String keyword = sc.nextLine().toLowerCase();
        String html = getHtml("https://www.114la.com");
        ArrayList arr = getHost(html);
        for (int i = 0; i < arr.size(); i++) {
            String str = (String)arr.get(i);
            if (isContains(str, keyword)) {
                System.out.println(str);
            }
        }
    }

    public static String getHtml(String addr) {
        String res = "";
        try {
            URL u = new URL(addr);
            URLConnection uc = u.openConnection();
            BufferedReader in = new BufferedReader(new InputStreamReader(uc.getInputStream()));
            String inputLine;
            while ((inputLine = in.readLine()) != null) {
                res = res + inputLine;
            }
        }
        catch (Exception e) {
            System.out.println("Have Exception");
        }
        return res;
    }

    public static ArrayList<String> getHost(String html) {
        Pattern p = Pattern.compile("([a-zA-Z\\d]+\\.)+?com[^a-zA-Z0-9]");
        Matcher m = p.matcher(html);
        Set<String> s = new TreeSet<String>();
        String str;
        ArrayList<String> res = new ArrayList<String>();
        while (m.find()) {
            str = m.group().toLowerCase();
            str = str.substring(0,str.length()-1);
            s.add(str);
        }
        for (Iterator<String> itr = s.iterator(); itr.hasNext();) {
            res.add(itr.next());
        }
        Collections.sort(res);
        return res;
    }

    public static boolean isContains(String str, String key) {
        if (str.indexOf(key) == -1) {
            return false;
        }
        return true;
    }
}