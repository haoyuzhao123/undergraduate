/*
 * Java Xiaoxueqi - Assignment 5
 * Whether i++ & ++i are atomic
 * Haoyu Zhao
 */

public class TestThread {
    public static int number1;
    public static int number2;

    public static void main(String[] args) {
        TestThread.number1 = 0;
        TestThread.number2 = 0;

        for (int i = 0; i < 1000; i++) {
            new Thread(new IntegerThread()).start();
        }

        System.out.println("TestThread.number1(i++): " + TestThread.number1);
        System.out.println("TestThread.number2(++i): " + TestThread.number2);
    }
}

class IntegerThread implements Runnable {
    public void run() {
        for(int i = 0; i < 1000; i++) {
            TestThread.number1++;
            ++TestThread.number2;
        }
    }
}