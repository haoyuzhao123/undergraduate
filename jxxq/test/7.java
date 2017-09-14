//7 regex

import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str1 = sc.nextLine();
        String str2 = sc.nextLine();
        Pattern p1 = Pattern.compile("[a-z]*");
        Matcher m = p1.matcher(str1);
        int idx = 0;
        int len = 0;
        while(idx < str1.length() && m.find(idx)) {
            int temp = m.end() - m.start();
            idx = m.start() + 1;
            if (temp > len) {
                len = temp;
            }
        }
        String n1 = "";
        idx = 0;
        while(m.find(idx)) {
            int temp = m.end() - m.start();
            idx = m.start() + 1;
            if (temp == len) {
                n1 = str1.substring(m.start(), m.end());
                break;
            }
        }

        Pattern p2 = Pattern.compile("[a-z.*]*");
        m = p2.matcher(str2);
        idx = 0;
        len = 0;
        while(idx < str2.length() && m.find(idx)) {
            int temp = m.end() - m.start();
            idx = m.start() + 1;
            if (temp > len) {
                len = temp;
            }
        }
        String n2 = "";
        idx = 0;
        while(m.find(idx)) {
            int temp = m.end() - m.start();
            idx = m.start() + 1;
            if (temp == len) {
                n2 = str2.substring(m.start(), m.end());
                break;
            }
        }

        String n = "^" + n2 + "$";

        Pattern p3 = Pattern.compile(n);
        Matcher res = p3.matcher(n1);
        System.out.println(n1);
        System.out.println(n2);
        if(res.find()) {
            System.out.println("YES");
        }
        else {
            System.out.println("NO");
        }
    }
}