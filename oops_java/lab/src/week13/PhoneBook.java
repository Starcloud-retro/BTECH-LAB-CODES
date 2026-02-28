package week13;

import java.io.*;
import java.util.*;
public class PhoneBook
{
    public static void main(String[] args)
    {
        try
        {
            FileInputStream fis=new FileInputStream("D:/RAJ/GCET/PROGRAMMING RELATED/2nd Year/OBJECT ORIENTED PROGRAMMING [JAVA]/GCET/src/week13/myfile.txt");
            Scanner sc=new Scanner(fis).useDelimiter("\t");
            Hashtable<String,String>  ht = new Hashtable<String,String> ();
            String[] strarray;
            String a,str;
            while(sc.hasNext())
            {
                a=sc.nextLine();
                strarray=a.split("\t");
                ht.put(strarray[0],strarray[1]);
                System.out.println("Hash Table values are: "+strarray[0]+" :: "+strarray[1]);
            }
            Scanner s=new Scanner(System.in);
            System.out.println("Enter the name as given in the Phone Book: ");
            str=s.next();
            if(ht.containsKey(str))
            {
                System.out.println("Phone No. is: "+ht.get(str));
            }
            else
            {
                System.out.println("Name is not Matched");
            }
        sc.close();
        s.close();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
}
