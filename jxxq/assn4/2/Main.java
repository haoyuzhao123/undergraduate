/*
 * Java Xiaoxueqi - Assignment 4 - Connected
 * Haoyu Zhao
 */

import java.util.Scanner;

class Main {
    public static void main(String[] main) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        UnionFind uf = new UnionFind(n);
        int a;
        int b;
        int i;
        for (i = 0; i < n-1; i++) {
            a = sc.nextInt() - 1;
            b = sc.nextInt() - 1;
            if (uf.inSameSet(a,b)) {
                System.out.println("NO");
                break;
            }
            uf.union(a,b);
        }
        if (i == n - 1)
            System.out.println("YES");
    }
}

class UnionFind {
    private int[] arr;
    private int count;

    public UnionFind(int n) {
        this.count = n;
        this.arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = -1;
        }
    }

    private int par(int n) {
        int count = n;
        while (true) {
            if (this.arr[count] < 0) {
                return count;
            }
            else {
                this.arr[count] = par(this.arr[count]);
                return this.arr[count];
            }
        }
    }

    public void union(int a, int b) {
        int pa = par(a);
        int pb = par(b);
        if (pa == pb) {
            return;
        }
        else {
            if (this.arr[pa] < this.arr[pb]) {
                this.arr[pb] = pa;
            }
            else {
                if (this.arr[pa] > this.arr[pb]) {
                    this.arr[pa] = pb;
                }
                else {
                    this.arr[pa] = pb;
                    this.arr[pb] --;
                }
            }
        }
    }

    public boolean inSameSet(int a, int b) {
        return par(a) == par(b);
    }
}