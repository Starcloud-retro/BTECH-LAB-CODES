// Dynamic Method Dispatch Example
package week4;

class Animal
{
    void sound()
    {
        System.out.println("Animal makes a sound");
    }
}

class Dog extends Animal
{
    void sound()
    {
        System.out.println("Dog barks");
    }
}

class Cat extends Animal
{
    void sound()
    {
        System.out.println("Cat meows");
    }
}

public class DynamicMethodDispatch
{
    public static void main(String[] args)
    {
        Animal ref; // Superclass reference

        ref = new Dog();  // ref points to Dog object
        ref.sound();      // Outputs: Dog barks

        ref = new Cat();  // ref points to Cat object
        ref.sound();      // Outputs: Cat meows
    }
}
