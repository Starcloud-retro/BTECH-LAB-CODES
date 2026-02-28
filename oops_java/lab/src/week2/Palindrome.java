//Given String is PALINDROME or Not!
package week2;
//import java.io.*;

public class Palindrome
{
    public static void main(String [] args)
    {
        String str = "MADAM";
        String revString = "";
        for(int i = str.length()-1; i>= 0; --i)
        {
            revString += str.charAt(i);
        }
        System.out.println(revString);
        if(revString.equalsIgnoreCase(str))
        {
            System.out.println("The String is a PALINDROME!");
        }
        else
        {
            System.out.println("Not a PALINDROME!");
        }
    }
    
}
