/*
 * Java Xiaoxueqi - Assignment 2 - Singleton
 * Haoyu Zhao
 */

class TestSingleton {
    public static void main(String[] args) {
        Singleton s = Singleton.getSingleton();
        s.printSingleton();
        s.increCount();
        Singleton sprime = Singleton.getSingleton();
        sprime.printSingleton();        
    }
}

class Singleton {
    private String name;
    private int count;
    //the only instatnce of this class "Singleton"
    private static Singleton single = new Singleton();

    //private constructor
    private Singleton() {
        name = "Singleton";
        count = 1;
    }

    public void printSingleton() {
        System.out.println("name = " + this.name);
        System.out.println("count = " + this.count);
    }

    //get the only instance from this public method
    public static Singleton getSingleton() {
        return Singleton.single;
    }

    public void increCount() {
        this.count += 1;
    }
}