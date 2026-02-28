//MultiLevel Inheritance

package week4;

class x
{
	public void method1()
	{
		System.out.println("Class X Method");
	}
}

class y extends x
{
	public void method2()
	{
		System.out.println("Class Y Method");
	}
}

class z extends y
{
	public void method3()
	{
		System.out.println("Class Z Method");
	}
}

public class MultiLevel
{
	public static void main(String [] args)
	{
		z obj = new z();
		obj.method1();
		obj.method2();
		obj.method3();		
	}
}
