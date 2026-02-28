//Write a Java program to implement Producer-Consumer problem using the concept of inter-thread communication.
package week7;

class Q
{
    int num;

    synchronized int get()
    {
        System.out.println("Got: " + num);
        return num;
    }
    synchronized void put(int num)
    {
        this.num = num;
        System.out.println("Put: " + num);
    }
}

class Producer implements Runnable
{
    Q que;

    Producer(Q que)
    {
        this.que = que;
        new Thread(this, "Producer").start();
    }
    public void run()
    {
        int n = 0;

        while(true)
        {
            que.put(n++);
        }
    }
}

class Consumer implements Runnable
{
    Q que;

    Consumer(Q que)
    {
        this.que = que;
        new Thread(this,"Consumer").start();
    }
    public void run()
    {
        while(true)
        {
            que.get();
        }
    }
}

public class ProducerConsumer
{
    public static void main(String[] args)
    {
        Q que = new Q();
        new Producer(que);
        new Consumer(que);

        System.out.println("Press Control-C to stop...");
    }
}