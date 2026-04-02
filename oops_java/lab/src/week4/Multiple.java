//Multiple Inheritance using Interfaces
package week4;

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
        System.out.println("Interface Item");
    }
    public void display1()
    {
        System.out.println("Interface Item1");
    }
}

public class Multiple
{
    public static void main(String[] args)
    {
        Item1 obj = new Temp();
        obj.display();
        obj.display1();
        System.out.println("The Number is: " + Item.a);
    }
}
