//DYNAMIC STACK
package week5;

interface dstackTop
{
    void push(int item);
    int pop();
}

class DynStack implements dstackTop
{
    private int[] stack;
    private int top;

    DynStack(int size)
    {
        stack = new int[size];
        top = -1;
    }

    public void push(int item)
    {
        if (top == stack.length - 1)
        {
            System.out.println("Resizing Stack");
            int[] t = new int[stack.length * 2];
            for (int i = 0; i < stack.length; i++)
                t[i] = stack[i];
            stack = t;
        }
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

public class DynamicStack
{
    public static void main(String[] args)
    {
        DynStack ds = new DynStack(5);
        dstackTop mystk;

        for (int i = 0; i < 7; i++)
            ds.push(i);

        System.out.println("Dynamic Stack Contents are:");
        for (int i = 0; i < 7; i++)
            System.out.println(ds.pop());

        mystk = ds;
        for (int i = 0; i < 7; i++)
            mystk.push(i);

        System.out.println("Dynamic Stack Contents Using Interface reference are:");
        for (int i = 0; i < 7; i++)
            System.out.println(mystk.pop());
    }
}
