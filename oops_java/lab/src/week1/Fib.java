package week1;
import java.util.Scanner;
public class Fib
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the number up to which you want to print the Fibonacci Series: ");
        int limit = s.nextInt();
        s.close();
        int first = 0, second = 1;
        System.out.println("Fibonacci Series up to " + limit + " is:");
        while (first <= limit)
        {
            System.out.println(first + " ");
            int next = first + second;
            first = second;
            second = next;
        }
    }
}