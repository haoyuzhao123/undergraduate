/*
 * Java Xiaoxueqi - Assignment 3 - Calculater
 * Haoyu Zhao
 */

import java.util.Scanner;
import java.util.Stack;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String exp = sc.nextLine();
        String nexp = addZero(addFrontBack(exp));

        try {
            System.out.println(String.format("%.2f", evaluate(nexp)));
        }
        catch (ZeroException e) {
            System.out.println(e);
        }
        catch (FormulaException ex) {
            System.out.println(ex);
        }
    }

    static String addFrontBack(String exp) {
        return "$" + exp + "$";
    }

    static String addZeroAt(String exp, int i) {
        return exp.substring(0,i) + "0" + exp.substring(i, exp.length());
    }

    static String addZero(String exp) {
        String nexp = new String(exp);
        int count = 0;
        for (int i = 0; i < exp.length(); i++) {
            if (exp.charAt(i) == '-') {
                if (exp.charAt(i-1) == '(' || exp.charAt(i-1) == '$') {
                    nexp = addZeroAt(nexp, i + count);
                    count++;
                }
            }
        }
        return nexp;
    }

    //readNumber(), always return a double, throws FormulaException when
    //can not change to double type
    static ReadNumRes readNumber(String exp, int index) throws FormulaException {
        double res = 0.0;
        int x = index;
        while (x < exp.length()) {
            if (exp.charAt(x) == '.' || (exp.charAt(x) >= '0' && exp.charAt(x) <= '9')) {
                x++;
            }
            else {
                break;
            }
        }

        String number = exp.substring(index, x);

        try {
            res = Double.parseDouble(number);
        }
        catch (Exception e) {
            FormulaException fex = new FormulaException();
            throw fex;
        }
        if (number.charAt(0) == '.' || number.charAt(number.length() - 1) == '.') {
            FormulaException fex = new FormulaException();
            throw fex;
        }
        if (number.length() >= 2 && number.charAt(0) == '0' && number.charAt(1) == '0') {
            FormulaException fex = new FormulaException();
            throw fex;
        }

        return new ReadNumRes(res, x);
    }

    // use a small abstraction, make calcu a interface, throws ZeroException
    static double calcu(double opnd1, char optr, double opnd2) throws ZeroException {
        if (optr == '/' && Math.abs(opnd2) < 0.0000001) {
            ZeroException e = new ZeroException();
            throw e;
        }
        double res = 0.0;
        switch (optr) {
            case '+':
                res = opnd1 + opnd2;
                break;
            case '-':
                res = opnd1 - opnd2;
                break;
            case '*':
                res = opnd1 * opnd2;
                break;
            case '/':
                res = opnd1 / opnd2;
                break;
        }
        return res;
    }

    //-1 : "<", 0 : " = ", 1 : " > ", 2 : " "
    static int orderBetween(char top, char cur) {
        int t = optrToNum(top);
        int c = optrToNum(cur);
        if (t == 1) {
            return 2;
        }
        if (t == 4 && c == 1) {
            return 0;
        }
        if (t == 0 && c == 1) {
            return 2;
        }
        if (t == 4 && c == 0) {
            return 2;
        }
        if (t == 0 && c == 0) {
            return 0;
        }
        if (t == 4) {
            return -1;
        }
        if (t >= c) {
            return 1;
        }
        else {
            return -1;
        }
    }

    static int optrToNum(char optr) {
        int res = -1;
        switch (optr) {
            case '(':
                res = 4;
                break;
            case ')':
                res = 1;
                break;
            case '+':
                res = 2;
                break;
            case '-':
                res = 2;
                break;
            case '*':
                res = 3;
                break;
            case '/':
                res = 3;
                break;
            case '$':
                res = 0;
                break;
        }
        return res;
    }

    static boolean isDigit(char c) {
        if (c == '.' || (c >= '0' && c <= '9')) {
            return true;
        }
        return false;
    }

    static double evaluate(String exp) throws ZeroException, FormulaException {
        Stack<Double> opnd = new Stack<Double>();
        Stack<Char> optr = new Stack<Char>();
        optr.push(new Char(exp.charAt(0)));
        int count = 1;
        while (!optr.isEmpty()) {
            if (isDigit(exp.charAt(count))) {
                ReadNumRes res = readNumber(exp, count);
                opnd.push(new Double(res.d));
                count = res.idx;
            }
            else {
                switch (orderBetween(optr.peek().getChar(), exp.charAt(count))) {
                    case -1:
                        optr.push(new Char(exp.charAt(count)));
                        count++;
                        break;
                    case 0:
                        try {
                            optr.pop();
                        }
                        catch (Exception e) {
                            FormulaException ex = new FormulaException();
                            throw ex;
                        }
                        count++;
                        break;
                    case 1:
                        char op = '$';
                        double opnd2 = 1;
                        double opnd1 = 0;
                        try {
                            op = optr.pop().getChar();
                            opnd2 = opnd.pop().doubleValue();
                            opnd1 = opnd.pop().doubleValue();
                        }
                        catch (Exception e) {
                            FormulaException ex = new FormulaException();
                            throw ex;
                        }
                        double result = 0;
                        try {
                            result = calcu(opnd1, op, opnd2);
                        }
                        catch (ZeroException e) {
                            throw e;
                        }
                        opnd.push(new Double(result));
                        break;
                    case 2:
                        FormulaException ex = new FormulaException();
                        throw ex;
                }
            }
        }
        double retVal = 0.0;
        if (opnd.size() > 1) {
            FormulaException ex = new FormulaException();
            throw ex;
        }
        try {
            retVal = opnd.pop().doubleValue();
        }
        catch (Exception e) {
            FormulaException ex = new FormulaException();
            throw ex;
        }
        return retVal;
    }
}

class ReadNumRes {
    public double d;
    public int idx;
    public ReadNumRes(double d, int idx) {
        this.d = d;
        this.idx = idx;
    }
}

// view 'char' type as an object
class Char {
    private char ch;
    public Char(char c) {
        this.ch = c;
    }
    public char getChar() {
        return this.ch;
    }
}

// define the ZeroException and FormulaException class
class ZeroException extends Exception {
    public String toString() {
        return "ZeroException";
    }
}

class FormulaException extends Exception {
    public String toString() {
        return "FormulaException";
    }
}