//METHOD OVERLOADING

package week3;
//import java.io.*;

public class Testing
{
    public void sum(int a)
    {
        System.out.println(a);
    }
    public void sum(int a, int b)
    {
        System.out.println(a+b);
    }
    public void sum(int a, int b, int c)
    {
        System.out.println(a+b+c);
    }
    public static void main(String [] args)
    {
        Testing t = new Testing();
        t.sum(10);
        t.sum(10, 20);
        t.sum(10, 20, 30);
    }    
}
