package week7;
import java.lang.Runnable;

public class ImplementRunnable
{
    public static void main(String args[])
    {
        X r = new X();
        Thread t = new Thread(r);
        t.start();
    }   
}
class X implements Runnable
{
    public void run()
    {
        for(int i = 1; i< 10; i++)
        {
            System.out.println("\tThread X: "+i);
        }
        System.out.println("Exit of Thread X");
    }
}