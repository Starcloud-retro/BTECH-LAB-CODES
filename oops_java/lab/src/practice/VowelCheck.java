package practice;
import java.util.Scanner;
public class VowelCheck {
    public static void main(String args[])
    {
        Scanner s= new Scanner(System.in);
        System.out.println("Enter string:");
        String str=s.nextLine();

        int hasvowel=0,consonant=0;
        for(int i=0;i<str.length();i++)
        {
            char ch=str.charAt(i);
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            {
                hasvowel++;
            }
            else
            {
                consonant++;
            }
        }
        s.close();
        System.out.println("Vowels count: "+hasvowel);
        System.out.println("Consonant count: "+consonant);
    }
    
}
