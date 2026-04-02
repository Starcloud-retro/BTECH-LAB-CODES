package week6;

//import java.io.*;
//import java.lang.*;

class MyException extends Exception
{
    String str1;
    MyException(String str2)
    {
        str1 = str2;
    }
    
    public String fromString()
    {
    	return ("Input String = "+str1);
    }
    public String toString()
    {
        return ("Output String = "+str1);
    }
    
}

public class User
{
    public static void main(String args[])
    {
        try
        {
            throw new MyException("User Defined exception");
        }
        catch(MyException e)
        {
            System.out.println("Hi, this is my Catch Block");
            System.out.println(e);
        }
    }
    
}
