package week1;

import java.util.Scanner;
//2 POWER FUNCTION
public class PowerFunction {
    static int count = 0;

    static long power(long a, int n) {
        if (n == 0) return 1;
        long half = power(a, n / 2);
        if (n % 2 == 0) {
            count++;
            return half * half;
        } else {
            count++;
            return a * half * half;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter base: ");
        long a = sc.nextLong();
        System.out.print("Enter exponent: ");
        int n = sc.nextInt();

        long result = power(a, n);
        System.out.println(a + "^" + n + " = " + result);
        System.out.println("Multiplication count = " + count);

        sc.close();
    }
}
