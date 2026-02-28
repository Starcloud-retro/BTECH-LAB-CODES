//FIXED STACK SIZE
package week5;

interface stackTop
{
    void push(int item);
    int pop();
}

class MyFixedStack implements stackTop
{
    private final int[] stack;
    private int top;

    MyFixedStack(int size)
    {
        stack = new int[size];
        top = -1;
    }

    public void push(int item)
    {
        if (top == stack.length - 1)
            System.out.println("Stack Overflows");
        else
            stack[++top] = item;
    }

    public int pop()
    {
        if (top < 0)
        {
            System.out.println("Stack Underflow");
            return 0;
        }
        else
        {
            return stack[top--];
        }
    }
}

public class FixedStack
{
    public static void main(String[] args)
    {
        MyFixedStack fs = new MyFixedStack(5);
        stackTop mystk;

        for (int i = 0; i < 3; i++)
            fs.push(i);

        System.out.println("Fixed Length Stack Contents are:");
        for (int i = 0; i < 3; i++)
            System.out.println(fs.pop());

        mystk = fs;
        for (int i = 0; i < 3; i++)
            mystk.push(i);

        System.out.println("Fixed Length Stack Contents Using Interface reference are:");
        for (int i = 0; i < 3; i++)
            System.out.println(mystk.pop());
    }
}
