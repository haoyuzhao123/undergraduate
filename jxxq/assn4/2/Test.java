import java.io.*;
import java.util.Random;
import java.util.ArrayList;
import java.util.Collections;

public class Test {
    public static void main(String[] args) {
        try {
            PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("test")));
            int num = 1000000;
            out.println(num);
            Random rand = new Random();
            ArrayList arr = new ArrayList();
            for (int i = 1; i < num; i++) {
                int j = rand.nextInt(i);
                int a = rand.nextInt(num);
                int b = rand.nextInt(num);
                Pair p = new Pair();
                p.first = i+1;
                p.second = j+1;
                arr.add(p);
            }
            Collections.shuffle(arr);
            for (int i = 0; i < num-1; i++) {
                int x = ((Pair)(arr.get(i))).first;
                int y = ((Pair)(arr.get(i))).second;
                out.println(x + " " + y);
            }
            out.close();
        }
        catch (Exception e) {

        }
    }
}

class Pair {
    public int first;
    public int second;
}