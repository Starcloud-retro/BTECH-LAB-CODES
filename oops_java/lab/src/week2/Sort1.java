//Sorting List of Names in Ascending Order
package week2;

public class Sort1
{
    public static void main(String [] args)
    {
        int n = 4;
        String names[] = {"Rahul", "Ajay", "Gourav", "Riya"};
        String temp;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if((names[i].compareTo(names[j])>0))
                {
                    temp = names[i];
                    names[i] = names[j];
                    names[j] = temp;
                }
            }
        }
        System.out.println("The name is alphabetical Order are: ");
        for(int i = 0; i < n; i++)
        {
            System.out.println(names[i]);
        }
    }
}
