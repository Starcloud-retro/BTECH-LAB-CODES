package beginning.Basics;

import java.util.Scanner;

public class Variable
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        String s1 = s.nextLine();
        System.out.println("Number is "+a+"String is "+s1);

        s.close();
    }
}
