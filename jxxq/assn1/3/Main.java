/*
 * Java Xiaoxueqi - Assignment 1 - Legal Identifier
 * Haoyu Zhao
*/

import java.util.Scanner;
import java.util.TreeSet;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        if (!isJavaIdentifier(str)) {
            System.out.println(-1);
        }
        else if (isJavaKeyWord(str)) {
            System.out.println(-1);
        }
        else {
            System.out.println(0);
        }
    }

    public static boolean isJavaIdentifier(String str) {
        int len = str.length();
        //the length must be greater than 0
        if (str == null || len == 0) {
            return false;
        }

        //use Java inbuild method to judge whether it is an identifier
        if (!Character.isJavaIdentifierStart(str.charAt(0))) {
            return false;
        }

        for (int i = 0; i < len - 1; i++) {
            if (!Character.isJavaIdentifierPart(str.charAt(i+1))) {
                return false;
            }
        }
        return true;
    }

    public static boolean isJavaKeyWord(String str) {
        //all the keywords in Java and the "true", "false", "null"
        String[] keywordsArr = {"abstract",	"continue", "for", "new", "switch",
                                "assert", "default", "goto", "package", "synchronized",
                                "boolean", "do", "if", "private", "this",
                                "break", "double", "implements", "protected", "throw",
                                "byte", "else", "import", "public", "throws",
                                "case", "enum", "instanceof", "return", "transient",
                                "catch", "extends", "int", "short",	"try",
                                "char",	"final", "interface", "static", "void",
                                "class", "finally", "long",	"strictfp",	"volatile",
                                "const", "float", "native",	"super", "while", "true", "false", "null"};
        //use TreeSet to store the keywords
        TreeSet set = new TreeSet();
        for (int i = 0; i < keywordsArr.length; i++) {
            set.add(keywordsArr[i]);
        }
        if (set.contains(str)) {
            return true;
        }
        return false;
    }
}