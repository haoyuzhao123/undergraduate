public class First implements Runnable {
    private int i = 0;
    private int sum = 0;
    private int u = 0;

    public First(int u) {
        this.u = u;
    }

    public void run() {
        int temp = 0;
        while (true) {
            temp = getNumber();
            if (temp > u) {
                return;
            }
            add(temp);
        }
    }

    public synchronized int getNumber() {
        i++;
        try {
            Thread.sleep(200);//1_ 让进程进入睡眠，把cpu资源让给其他进程，在未改动的代码中，
                                //使得多个进程的getNumber()可以同时访问i这个变量。

        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        return i;
    }

    public synchronized void add(int offset) {
        int temp = sum += offset;
        try {
            Thread.sleep(300);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        sum = temp;
    }

    public void print() {
        System.out.println(sum);
    }


    public static void main(String[] args) throws InterruptedException {//2_　sleep 和 join方法都会抛出
                                                                        //InterruptedException异常，然而
                                                                        //sleep抛出的异常在函数体内已经捕获，
                                                                        //所以这里主要是考虑join抛出的异常
        int u = 10;
        First test = new First(u);
        Thread[] tt = new Thread[5];

        for (int i = 0; i < tt.length; i++) {
            tt[i] = new Thread(test);//3_　建立5个进程来进行 1+2+...+u 的计算
            tt[i].start();
        }

        for (int i = 0; i < tt.length; i++) {
            tt[i].join();//4_　join()方法保证了只有结束该进程才会继续进行下去。这样会先让5个计算进程结束，才会执行test.print().
        }
        test.print();
    }

}