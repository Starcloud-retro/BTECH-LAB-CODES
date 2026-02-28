package practice;

interface Area
{
    final double PI = 3.14;
    double Compute(double x, double y);
}

class Rectangle implements Area
{
    public double Compute(double l, double b)
    {
        return (l*b);
    }
}

class Circle implements Area
{
    public double Compute(double x, double y)
    {
        return (PI*x*x);
    }
}


public class TestInterface
{
    public static void main(String [] args)
    {
        Rectangle rect = new Rectangle();
        Circle cir = new Circle();

        Area area;
        area = rect;
        System.out.println("Area of RECT: "+area.Compute(40, 50));

        area = cir;
        System.out.println("Area of CIR: "+area.Compute(10.0,0.0));
    }
    
}
