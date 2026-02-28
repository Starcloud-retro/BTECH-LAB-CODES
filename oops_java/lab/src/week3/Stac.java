package week3;

public class Stac
{
    private int[] arr;
    private int top;
    private int capacity;

    Stac(int size)
    {
        arr = new int[size];
        capacity = size;
        top = -1;
    }
    public void push(int x)
    {
        if(isFull())
        {
            System.out.println("Stack Overflow");
            System.exit(1);
        }
        arr[++top] = x;
    }
    public int pop()
    {
        if(isEmpty())
        {
            System.out.println("Stack is Empty");
            System.exit(1);
        }
        return arr[top--];
    }
    public int peek()
    {
        if(isEmpty())
        {
            System.out.println("Stack is Empty!");
            System.exit(1);
        }
        return arr[top];
    }
    public int size()
    {
        return top+1;
    }
    public boolean isEmpty()
    {
        return top == -1;
    }
    public boolean isFull()
    {
        return top == capacity-1;
    }
    public static void main(String [] args)
    {
        Stac stack = new Stac(5);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        System.out.println("Top of the Stack is: "+stack.peek());
        System.out.println("Size of the Stack is: "+stack.size());
        System.out.println("Popped Element is: "+stack.pop());
        System.out.println("Top of the Stack after pop is: "+stack.peek());
        System.out.println("Size of the stack after pop: "+stack.size());
    }
    
}
