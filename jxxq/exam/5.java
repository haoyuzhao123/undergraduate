// Inverse
//Haoyu Zhao

import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String res = "";
        if (str.charAt(0) == '-') {
            res = res + '-';
            str = str.substring(1,str.length());
        }
        String temp = "";
        for (int i = 0; i < str.length(); i++) {
            temp = temp + str.charAt(str.length() - 1 - i);
        }
        res = res + temp;
        int a;
        try {
            a = Integer.parseInt(res);
            System.out.println(a);
        }
        catch (Exception e) {
            System.out.println("OverflowException");
        }
    }
}