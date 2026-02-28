//check if ODD
package practice;

import java.util.*;
//import java.io.*;

// public class ClassWork
// {
// 	// int MAX = 5;
// 	// int [] a = {1, 2, 3, 4, 5};
// 	// int [] b = new int[MAX];

// 	static int check(String s)
// 	{
// 		int [] temp ;
// 		//for(int i = 0; i < s.length()-1; i++)
// 		{
// 			//if(temp % 2 != 0)
// 			{
// 				return 1;
// 			}
// 		}
// 		//return 0;
// 	}

// 	public static void main(String args[])
// 	{
// 		Scanner scan = new Scanner(System.in);
// 		System.out.println("Enter the Number of numbers you want to check:");
// 		int limit = scan.nextInt();
// 		while(limit != 0)
// 		{
// 			System.out.println("Enter a Number: ");
// 			int str = scan.nextInt();
// 			limit++;
// 		}


// 		scan.close();
// 	}

// }

public class EvenOdd
{
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number: ");
        int num = sc.nextInt();
        int Even = 0, Odd = 0, zeroes = 0;
        while(num != 0)
        {
            int digit = num % 10;
            if(digit == 0)
            {
                zeroes++;
            }
            else if(digit % 2 == 0)
            {
                Even++;
            }
            else
            {
                Odd++;
            }
            num /= 10;
        }
        System.out.println("Even digits: " + Even);
        System.out.println("Odd digits: " + Odd);
        System.out.println("Zeroes: " + zeroes);
        sc.close();
    }
}
