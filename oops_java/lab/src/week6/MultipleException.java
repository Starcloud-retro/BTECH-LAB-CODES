//MultipleExceptions
package week6;
//import java.io.*;

public class MultipleException
{
    @SuppressWarnings("unused")
    public static void main(String [] args)
    {
        int a, b, c;
        try
        {
            try
            {
                a = 0;
                b = 10;
                c = b/a;
                System.out.println("The line will not be executed.");
            }
            catch(ArithmeticException e)
            {
                System.out.println("Divided by Zero");
            }
            String firstArg = args[0];
            System.out.println("First Argument: "+firstArg);
        }
        catch(IndexOutOfBoundsException ex)
        {
            System.out.println("There is no Argument.");
        }
        finally
        {
            System.out.println("Finally gets Executed.");
        }
    }
}
