import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Iterator;
import java.util.TreeSet;

public class test {
    public static void main(String[] args) {
        try {
            ObjectOutputStream oos = new ObjectOutputStream(
                new FileOutputStream("testset"));
            TreeSet<String> set = new TreeSet<String>();
            set.add("1");
            set.add("2");
            set.add("4");
            set.add("8");
            oos.writeObject(set);
            oos.close();
        }
        catch (Exception e) {
            System.out.println("exception happens in write");
        }
        try {
            ObjectInputStream ois = new ObjectInputStream(new FileInputStream("testset"));
            TreeSet<String> t = (TreeSet<String>)ois.readObject();
            Iterator<String> iter = t.iterator();
            while (iter.hasNext()) {
                System.out.println(iter.next());
            }
            ois.close();
        }
        catch (Exception e) {
            System.out.println("exception happens in read");
        }
    }
}