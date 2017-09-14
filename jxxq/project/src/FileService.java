//package com.java.group46_csq.fileIO;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

import java.io.EOFException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

//import com.java.group46_csq.util.News;
/**
 * Created by csq on 17/9/12.
 */

public class FileService {

    public FileService() {

    }


    public static void saveNews(String filename, News news) throws Exception {
        FileOutputStream fos = null;
        try {
            fos = new FileOutputStream(filename, true);
        }
        catch (FileNotFoundException e) {
            System.out.println("fileNotFound");
        }
        //System.out.println("fos initialized");
        ObjectOutputStream oso = new ObjectOutputStream(fos);
        //System.out.println("oso initializd");
        try {
            oso.writeObject(news);
        }
        catch (IOException e) {
            e.printStackTrace();
            System.out.println("IOException");
        }
        //System.out.println("oso writed");
        oso.close();
        //System.out.println("oso close");
    }

    public static News findIfSaved(String filename, News news) throws Exception {
        FileInputStream fis = new FileInputStream(filename);
        //System.out.println("fis initialized");
        ObjectInputStream osi = new ObjectInputStream(fis);
        //System.out.println("osi initialized");

        News res = new News();

        try {
            while(true) {
                News news1 = (News) osi.readObject();
                byte[] buf = new byte[4];
                fis.read(buf);
                //System.out.println("read object.");
                //System.out.println(news1.getNewsID());
                //System.out.println();
                if(news1.equals(news1,news)){
                    //System.out.println("equals!");
                    res = news1;
                    break;
                }

            }
        }
        catch(EOFException e) {
            e.printStackTrace();
            System.out.println("exception happens");
        }
        finally {
            osi.close();
            return res;
        }
    }

    public static void main(String[] args) {
        News n1 = new News();
        n1.setNewsID("012345678");
        n1.setNewsTitle("test the file");
        n1.setNewsIntro("abcdef");
        try {
            saveNews("test", n1);
        }
        catch (Exception e) {
            System.out.println("exception happens at saveNews");
        }

        News n3 = new News();
        try {
            saveNews("test", n3);
        }
        catch (Exception e) {
            System.out.println("exception happens at saveNews");
        }

        News n2 = new News();
        n2.setNewsID("01234");
        n2.setNewsTitle("test the file 2");
        n2.setNewsIntro("abcdefghijk");
        try {
            saveNews("test", n2);
        }
        catch (Exception e) {
            System.out.println("exception happens at saveNews");
        }


        News t = new News();
        
        try {
            t = findIfSaved("test", n2);
        }
        catch (Exception e) {
            System.out.println("exception happens at findIfSaved");
        }
        

        System.out.println(t.getNewsID());
        System.out.println(t.getNewsTitle());

        String str1 = null;
        String str2 = "a";
        //System.out.println(str1.equals(str2));
    }

}