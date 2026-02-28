package practice;
import java.util.Scanner;
public class Fibo {
	public static void main(String [] args) {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter Series LImit : ");
		int n = sc.nextInt();
		
		int f1 = 0;
		int f2 = 1;
		System.out.print("Series : ");
		if(n==1) {
			
		}
		if(n >= 2)
		System.out.print(f1+" "+f2 +" ");
		int f3 = f1 +f2;
		
		while(f3 <= n) {
			System.out.print(f3 + " ");
			f1 = f2 ;
			f2 = f3;
			f3 = f1 + f2;
		}
		
		sc.close();
	}
	
}
