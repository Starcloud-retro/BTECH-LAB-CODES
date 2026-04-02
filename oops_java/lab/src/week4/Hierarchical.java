//HierarchialInheritance

package week4;

class A
{
    public void display()
    {
        System.out.println("Base Class Method");
    }
}

class B extends A
{
    public void print()
    {
        System.out.println("Derived Class Method");
    }
}

class C extends A
{
    public void display1()
    {
        System.out.println("Method of Class C");
    }
}

public class Hierarchical
{
    public static void main(String[] args)
    {
        B b1 = new B();
        b1.display();
        b1.print();

        C c1 = new C();
        c1.display();
        c1.display1();
    }
}
