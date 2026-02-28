package examprac;


public class demo
{
    public static void main (String args [])
    {
        int A[] = new int[5];
        try
        {
            try
            {
                for(int c = 0; c < 5; c++)
                {
                    //do nothing
                }
            }
            catch(Exception e)
            {
                System.out.println(e);
            }
            finally {
                System.out.println("Hi");
            }
            for (int c = 0; c < 5; c++)
            {
                System.out.println(c + ". Current: " + A[c]);
                A[c] = c/c;
            }
        }
        catch (ArrayIndexOutOfBoundsException e)
        {
            System.out.println ("Array out of bound ");
        }
        catch (ArithmeticException e)
        {
            System.out.println ("Zero divide error");
        }
    }
}