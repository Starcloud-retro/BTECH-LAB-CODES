package week3;
//import java.io.*;

public class Student
{
     Student(String name)
    {
        //This Constructor has one parameter name
        System.out.println("Passed Name is: " +name);
    }
    @SuppressWarnings("unused")
    public static void main(String[]args)
    {
        Student s = new Student("Rakesh");
    }    
}
