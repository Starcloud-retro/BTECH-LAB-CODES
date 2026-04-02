package examprac;

// Step 1: Create a class that extends Thread
class MyThread extends Thread
{
    int i = 1;
    public void printMessage(int message)
    {
        System.out.println(message+". Hello from printMessage method!");
    }

    public void run()
    {

        printMessage(i);
        i++;
        // Code that runs in this thread
        System.out.println("Thread running: " + Thread.currentThread().getName());
    }


}

public class ThreadExample1
{
    public static void main(String[] args)
    {
        // Step 2: Create objects of MyThread
        MyThread t1 = new MyThread();
        MyThread t2 = new MyThread();

        // Step 3: Start threads
        t1.start();
        t2.start();
    }
}
