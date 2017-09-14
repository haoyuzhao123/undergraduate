// divide the tree
// Haoyu Zhao

import java.util.*;

class Main {
    static int[] arr;
    static int[] sumarr;

    public static int pow(int a, int b) {
        if (b == 0) {
            return 1;
        }
        else {
            return a * pow(a, b-1);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        arr = new int[pow(2,n) - 1];
        sumarr = new int[pow(2,n) - 1];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }
        compute();
        int total = sumarr[0];
        if (total % 2 == 1) {
            System.out.println("NO");
        }
        else {
            int temp = total / 2;
            for (int i = 0; i < sumarr.length; i++) {
                if (sumarr[i] == temp) {
                    System.out.println(temp);
                    return;
                }
            }
            System.out.println("NO");
        }
    }

    public static void compute() {
        for (int i = arr.length - 1; i >= 0; i--) {
            int t = arr[i];
            int a = 0;
            int b = 0;
            int cur = t;
            if (t == -1) {
                cur = 0;
            }
            int lc = 2 * i + 1;
            int rc = 2 * i + 2;
            if (lc < arr.length) {
                a = sumarr[lc];
            }
            if (rc < arr.length) {
                b = sumarr[rc];
            }
            sumarr[i] = cur + a + b;
        }
    }

    
}