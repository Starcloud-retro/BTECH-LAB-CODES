//SingleInheritance

package week4;

class Asi
{
	public void disp()
	{
		System.out.println("Base Class Method");
	}
}

class Bsi extends Asi
{
	public void display()
	{
		System.out.println("Child Class Method");
	}
}

public class SingleInheritance
{
    public static void main(String args[])
    {
        Bsi obj = new Bsi();
        obj.disp();
        obj.display();
    }
    
}
