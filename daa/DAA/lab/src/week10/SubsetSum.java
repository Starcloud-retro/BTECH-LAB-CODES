package week10;

import java.util.*;

public class SubsetSum {

    static int n, m;
    static int[] w = new int[50];   // weights
    static int[] x = new int[50];   // solution array (0/1)

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of weights: ");
        n = sc.nextInt();

        System.out.println("Enter the weights:");
        for (int i = 1; i <= n; i++) {
            w[i] = sc.nextInt();
        }

        System.out.print("Enter target sum (m): ");
        m = sc.nextInt();

        // Sort weights (IMPORTANT for pruning logic)
        Arrays.sort(w, 1, n + 1);

        int r = 0;
        for (int i = 1; i <= n; i++) {
            r += w[i];
        }

        if (m > r) {
            System.out.println("No possible solution");
        } else {
            System.out.println("Possible subsets (0/1 format):");
            sos(0, 1, r);
        }

        sc.close();
    }

    // Backtracking function
    static void sos(int s, int k, int r) {

        if (k > n) return;  // safety check

        // INCLUDE current element
        x[k] = 1;

        if (s + w[k] == m) {
            printSolution();
        }
        else if (k + 1 <= n && (s + w[k] + w[k + 1] <= m)) {
            sos(s + w[k], k + 1, r - w[k]);
        }

        // EXCLUDE current element
        if (k + 1 <= n && (s + r - w[k] >= m) && (s + w[k + 1] <= m)) {
            x[k] = 0;
            sos(s, k + 1, r - w[k]);
        }
    }

    // Print solution
    static void printSolution() {
        for (int i = 1; i <= n; i++) {
            System.out.print(x[i] + " ");
        }
        System.out.println();
    }
}