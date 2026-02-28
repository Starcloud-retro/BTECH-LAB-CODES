//METHOD OVERRIDING
package week4;

class ABC
{
    public void disp()
    {
        System.out.println("disp() method of the parent class");
    }
    public void abc()
    {
        System.out.println("abc() method of the parent class");
    }
}

class Test extends ABC
{
    public void disp()
    {
        System.out.println("disp() method of child class");
    }
    public void xyz()
    {
        System.out.println("xyz() method of child class");
    }
}

public class MethodOverriding
{
    public static void main(String [] args)
    {
        ABC obj = new Test();
        obj.disp();//child
        obj.abc();
    }
    
}
