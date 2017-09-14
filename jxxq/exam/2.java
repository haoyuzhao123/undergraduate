//list all the files

import java.io.*;
import java.util.*;

class Main{
    static ArrayList<String> arr;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String keyword = sc.nextLine();
        keyword = keyword.toLowerCase();
        arr = new ArrayList<String>();
        try {
            String fileName="/usr/include/linux/";
            System.out.println(fileName.length());
            File f = new File(fileName);
            allFile(f);
        }
        catch (Exception e) {}

        Collections.sort(arr);
        for (int i = 0; i < arr.size(); i++) {
            if (isContains(arr.get(i), keyword)) {
                System.out.println(arr.get(i));
            }
        }

    }
    public static void allFile(File f){
        if(f!=null){
            if(f.isDirectory()){
                File[] fileArr=f.listFiles();
                if(fileArr!=null){
                    for (int i = 0; i < fileArr.length; i++) {
                        allFile(fileArr[i]);
                    }
                }
            }
            else{
                String s = f.toString();
                int len = s.length();
                arr.add(s.substring(19,len));
            }
        }
    }

    public static boolean isContains(String str, String key) {
        if (str.toLowerCase().indexOf(key) == -1) {
            return false;
        }
        return true;
    }
}