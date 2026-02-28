package week5;

class Outer
{
    int count;
    public void display()
    {
        for(int i = 0; i < 5; i++)
        {
            class Inner
            {
                public void show()
                {
                    System.out.println("Inside Inner: "+(count++));
                }
            }
            Inner in = new Inner();
            in.show();
        }
    }
}

public class InnerTest
{
    public static void main(String [] args)
    {
        Outer ot = new Outer();
        ot.display();
    }
    
}
