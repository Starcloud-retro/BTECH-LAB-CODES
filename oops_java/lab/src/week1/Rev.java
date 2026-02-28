package week1;
import java.util.Scanner;
public class Rev
{
    public static int reverse(int number)
    {
        int reverse = 0;
        while(number != 0)
        {
            int digit = number % 10;
            reverse = reverse * 10 + digit;
            number /= 10;
        }
        return reverse;
    }
    public static void main(String [] args)
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a Number: ");
        int number = scanner.nextInt();
        int reversedNumber = reverse(number);
        System.out.println("Rversed Number: "+reversedNumber);
        scanner.close();
    }
    
}
