package examprac;

// Step 1: Create a class that implements Runnable
class MyRunnable implements Runnable
{
    public void run()
    {
        System.out.println("Thread running: " + Thread.currentThread().getName());
    }
}

public class ThreadExample2
{
    public static void main(String[] args)
    {
        // Step 2: Create Runnable object
        MyRunnable r = new MyRunnable();

        // Step 3: Pass it to Thread object
        Thread t1 = new Thread(r);
        Thread t2 = new Thread(r);

        // Step 4: Start threads
        t1.start();
        t2.start();
    }
}

