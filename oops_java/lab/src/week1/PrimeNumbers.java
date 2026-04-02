package week1;
import java.util.*;

public class PrimeNumbers
{
    public static void main(String [] args)
    {
        int n, p;
        Scanner s = new Scanner(System.in);
        System.out.print("Enter a Number: ");
        n = s.nextInt();
        for(int i = 2; i < n; i++)
        {
            p = 0;
            for(int j = 2; j < i; j++)
            {
                if(i % j == 0)
                {
                    p = 1;
                }
            }
            if(p == 0)
            {
                System.out.println(i);
            }
        }
        s.close();
    }    
}
