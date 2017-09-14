/*
 * Java Xiaoxueqi - project
 * GetNetRes Source File
 * Created by Haoyu Zhao on Sep 8, 2017
 */

import java.net.URL;
import java.net.URLConnection;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class GetNetRes {
    //this is a simple method which aims to get the html/json from the given url
    public static String getUrlRes(String urlstr) {
        String res = "";
        try {
            URL u = new URL(urlstr);
            URLConnection uc = u.openConnection();
            BufferedReader in = new BufferedReader(new InputStreamReader(uc.getInputStream()));
            String inputLine = null;
            while ((inputLine = in.readLine()) != null) {
                res = res + inputLine;
            }
        }
        catch (Exception e) {
            System.out.println("Exception happens");
        }
        return res;
    }

    public static void main(String[] args) {
        String str =  "http://166.111.68.66:2042/news/action/query/search?keyword=北京&pageNo=1&pageSize=20";
        String json = getUrlRes(str);
        System.out.println(json);
    }
}