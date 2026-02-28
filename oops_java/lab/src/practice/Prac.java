package practice;

public class Prac
{
    int a = 5;
    void display()
    {
        class SubProg
        {
            public void display()
            {
                System.out.println("SuM: "+(a+a));
            }
        }
        SubProg sp = new SubProg();
        sp.display();
    }

    public static void main(String[] args)
    {
        Prac p = new Prac();
        p.display();
    }  
}
