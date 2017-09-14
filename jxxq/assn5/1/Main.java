/*
 * Java Xiaoxueqi - Assignment 5 - Simple Calender
 * Haoyu Zhao
 */

import java.text.SimpleDateFormat;
import java.util.Calendar;


class SimpleCalender {
    public static void main(String[] args) {
        Clock c = new Clock("c");
        c.start();
    }

}

class Clock extends Thread {
    public Clock(String str) {
        super(str);
    }

    public void run() {
        SimpleDateFormat dformat = new SimpleDateFormat("[yyyy/MM/dd][hh:mm:ss]");
        try {
            while (true) {
                System.out.println(dformat.format(Calendar.getInstance().getTime()));
                sleep(1000);
            }
        }
        catch (InterruptedException e) {

        }
    }
}