//Middle Number
//Haoyu Zhao

import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> arr = new ArrayList<Integer>();
        String str1 = sc.nextLine();
        String str2 = sc.nextLine();
        String input = str1 + " " + str2;
        sc = new Scanner(input);
        while (sc.hasNextInt()) {
            arr.add(new Integer(sc.nextInt()));
        }
        Collections.sort(arr);
        int len = arr.size();
        if (len % 2 == 1) {
            int n = len / 2;
            System.out.println(arr.get(n).intValue());
        }
        else {
            int n = len / 2;
            int a = arr.get(n-1).intValue();
            int b = arr.get(n).intValue();
            System.out.println((a+b+1) / 2);
        }
    }
}