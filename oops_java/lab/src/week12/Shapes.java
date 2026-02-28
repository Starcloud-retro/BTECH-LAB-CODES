package week12;

abstract class Shape
{
    abstract int numberOfSides();
}

class Trapezoid extends Shape
{
    private static int sides=4;
    int numberOfSides()
    {
        return sides;
    }
    public String toString()
    {
        return "Trapezoid";
    }
}

class Triangle extends Shape
{
    private static int sides=3;
    int numberOfSides()
    {
        return sides;
    }
    public String toString()
    {
        return "Triangle";
    }
}
class Hexagon extends Shape
{
    private static int sides = 6;
    int numberOfSides()
    {
        return sides;
    }
    public String toString()
    {
        return "Hexagon";
    }
}
public class Shapes
{
    public static void main(String [] args)
    {
        Shape[] shapes = new Shape[4];
        Trapezoid tp = new Trapezoid();
        Triangle tr = new Triangle();
        Hexagon hx = new Hexagon();
        shapes[0]=tp;
        shapes[1]=tr;
        shapes[2]=hx;
        for(int i=0 ; i<3 ;i++)
        {
            System.out.println(shapes[i].toString()+" #sides:"+shapes[i].numberOfSides());
        }
    }
}
