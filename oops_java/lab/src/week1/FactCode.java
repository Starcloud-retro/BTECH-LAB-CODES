/*
NOTE: this is a "Command Line Argument Program", to run this in VS Code.... do the following Commands in the Terminal
    :
    cd "D:\RAJ\Geethanjali College of Engineering and Technology\PROGRAMMING RELATED\2nd Year\OBJECT ORIENTED PROGRAMMING ``[JAVA``]\GCET\"
    (then)
    javac src/week1/FactCode.java
    (then)
    java -cp src week1.FactCode 5
 */

package week1;
public class FactCode
{
    public static void main(String []args)
    {
        int f=1, n, i;
        n = Integer.parseInt(args[0]);
        for(i = 1; i <= n; i++)
        {
            f = f * i;
        }
        System.out.println("Factorial of "+n+" is: "+f);
        System.out.printf("Fact is : %d",f);
    }
}