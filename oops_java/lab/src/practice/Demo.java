package practice;

interface Item
{
    int a = 5;
    void display();
}
interface Item1 extends Item
{
    void display1();
}

class Temp implements Item1
{
    public void display()
    {
        System.out.println("Item");
    }
    public void display1()
    {
        System.out.println("Item1");
    }
}

public class Demo
{
    public static void main(String [] args)
    {
        Item1 obj = new Temp();
        obj.display();//Item
        obj.display1();//Item1
    }
    
}
