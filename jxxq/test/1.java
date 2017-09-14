//Wen we shu
//Haoyu Zhao

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        if (isSatisfy(str)) {
            System.out.println("YES");
        }
        else {
            System.out.println("NO");
        }
    }

    public static boolean isSatisfy(String str) {
        int len = str.length();
        for (int i = 0; i < len; i++) {
            if (str.charAt(i) != str.charAt(len - 1 - i)) {
                return false;
            }
        }
        return true;
    }
}