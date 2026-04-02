import java.util.*;

public class knapsack {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // Input
        System.out.print("Enter number of items: ");
        int n = sc.nextInt();

        int[] w = new int[n];
        int[] p = new int[n];

        System.out.println("Enter weights:");
        for (int i = 0; i < n; i++) {
            w[i] = sc.nextInt();
        }

        System.out.println("Enter profits:");
        for (int i = 0; i < n; i++) {
            p[i] = sc.nextInt();
        }

        System.out.print("Enter knapsack capacity: ");
        int W = sc.nextInt();

        int[][] K = new int[n + 1][W + 1];

        // Initialize
        for (int i = 0; i <= n; i++) K[i][0] = 0;
        for (int j = 0; j <= W; j++) K[0][j] = 0;

        // Tabulation
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= W; j++) {

                if (w[i - 1] <= j) {
                    K[i][j] = Math.max(
                        K[i - 1][j],
                        p[i - 1] + K[i - 1][j - w[i - 1]]
                    );
                } else {
                    K[i][j] = K[i - 1][j];
                }
            }
        }

        // Max profit
        System.out.println("Maximum Profit = " + K[n][W]);

        // 🔹 Backtracking → store 0/1 selection
        int[] selected = new int[n]; // 0 or 1

        int i = n, j = W;

        while (i > 0 && j > 0) {
            if (K[i][j] != K[i - 1][j]) {
                selected[i - 1] = 1;   // item taken
                j = j - w[i - 1];
            } else {
                selected[i - 1] = 0;   // not taken
            }
            i--;
        }

        // 🔹 Print weights
        System.out.println("Weights:");
        for (int k = 0; k < n; k++) {
            System.out.print(w[k] + " ");
        }

        // 🔹 Print 0/1 selection
        System.out.println("\nSelected (1 = taken, 0 = not taken):");
        for (int k = 0; k < n; k++) {
            System.out.print(selected[k] + " ");
        }

        sc.close();
    }
}