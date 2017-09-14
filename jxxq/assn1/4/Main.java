/*
 * Java Xiaoxueqi - Assignment1 - Matrix Multiplication
 * Haoyu Zhao
*/

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] A, B;
        int m,n;
        //input of the first matix
        m = sc.nextInt();
        n = sc.nextInt();
        A = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = sc.nextInt();
            }
        }

        //input of the second matrix
        m = sc.nextInt();
        n = sc.nextInt();
        B = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                B[i][j] = sc.nextInt();
            }
        }

        //compute the matrix multiplication
        int[][] C = matrixProduct(A, B);

        //output the result matrix
        m = C.length;
        n = C[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(C[i][j] + " ");
            }
            System.out.print("\r\n");
        }
    }

    public static int[][] matrixProduct(int[][] A, int[][] B) {
        int[][] C;
        int m = A.length;
        int n = A[0].length;
        int p = B.length;
        int q = B[0].length;

        if (n != p) {
            System.out.println("Size do not match");
            return null;
        }

        C = new int[m][q];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < q; j++) {
                int sum = 0;
                for (int k = 0; k < n; k++) {
                    sum += A[i][k] * B[k][j];
                }
                C[i][j] = sum;
            }
        }
        return C;
    }
}