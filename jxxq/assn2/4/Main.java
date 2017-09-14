/*
 * Java Xiaoxueqi - Assignment 2 - Distance
 * Haoyu Zhao
 */

import java.util.Scanner;

class Main {
    final static int INF = 100000000;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        int x, y;
        Point p;
        n = sc.nextInt();
        //input n points
        Point[] points = new Point[100];
        for (int i = 0; i < n; i++) {
            x = sc.nextInt();
            y = sc.nextInt();
            points[i] = new Point(x, y);
        }
        //input the last point
        x = sc.nextInt();
        y = sc.nextInt();
        p = new Point(x, y);

        //find the smallest distance with the last point
        int dist = INF;
        for (int i = 0; i < n; i++) {
            int distBetw = p.squaredDist(points[i]);
            if (distBetw < dist) {
                dist = distBetw;
            }
        }
        //print the point
        for (int i = 0; i < n; i++) {
            if (p.squaredDist(points[i]) == dist) {
                points[i].printPoint();
            }
        }
    }
}

class Point {
    int x;
    int y;
    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    int squaredDist(Point p) {
        int res = (this.x - p.x) * (this.x - p.x) + (this.y - p.y) * (this.y - p.y);
        return res;
    }

    void printPoint() {
        System.out.println(this.x + " " + this.y);
    }
}