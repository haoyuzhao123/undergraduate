/*
 * Java Xiaoxueqi - Preperation for the exam
 * Test the Comparable interface
 * Haoyu Zhao
 */


import java.util.ArrayList;
import java.util.Collections;

public class TestComparable {
    public static void main(String[] args) {
        ArrayList<Students> arr = new ArrayList<Students>();
        arr.add(new Students(3,"a"));
        arr.add(new Students(1,"z"));
        arr.add(new Students(3,"z"));
        arr.add(new Students(3,"x"));
        arr.add(new Students(5,"a"));
        Collections.sort(arr);
        for (int i = 0; i < arr.size(); i++) {
            System.out.println(arr.get(i));
        }
    }
}

class Students implements Comparable {
    public int id;
    public String name;

    public Students() {
        this.id = 0;
        this.name = null;
    }

    public Students(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public int compareTo(Object b) {
        Students o = (Students)b;
        if (this.id < o.id) {
            return -1;
        }
        else if (this.id > o.id) {
            return 1;
        }
        else {
           return this.name.compareTo(o.name);
        }
    }

    public String toString() {
        String res = this.id + " " + this.name;
        return res;
    }
}