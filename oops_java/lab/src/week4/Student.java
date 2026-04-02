//STATIC KEYWORD with Variable and Methods
package week4;

public class Student
{
	int roll_no;
	String name;
	static String college = "GCET";
	Student(int r, String n)
	{
		roll_no = r;
		name = n;
	}
	static void change()
	{
		college = "Geethanjali College of Institutions";
	}
	void display()
	{
		System.out.println(roll_no+" "+name+" "+college);
	}
	public static void main(String args[])
	{
		Student s1 = new Student(111, "Kiran");
		Student s2 = new Student(222, "Rakesh");
		s1.display();
		Student.change();
		s2.display();
	}
//	111 Kiran GCET
//	222 Rakesh Geethanjali College of Institutions

}
