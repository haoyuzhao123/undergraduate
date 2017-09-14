/*
 * Java Xiaoxueqi - Assignment 1 - Prime number
 * Haoyu Zhao
*/

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int count = 0;
        int num = 1;
        while (true) {
            if (isPrime(num)) {
                count++;
            }
            if (count == n) {
                break;
            }
            num++;
        }
        System.out.println(num);
    }

    public static boolean isPrime(int n) {
        if (n == 1) {
            return false;
        }
        if (n == 2) {
            return true;
        }
        boolean res = true;
        for (int i = 2; i < Math.sqrt(n) + 1; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}