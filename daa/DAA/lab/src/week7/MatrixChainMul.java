import java.util.Scanner;

public class MatrixChainMul {

    static int[][] M;
    static int[][] S;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of matrices: ");
        int n = sc.nextInt();

        int[] p = new int[n + 1];

        System.out.println("Enter dimensions array:");
        for (int i = 0; i <= n; i++) {
            p[i] = sc.nextInt();
        }

        matrixChainOrder(p, n);

        System.out.println("Minimum cost: " + M[1][n]);

        System.out.print("Optimal Parenthesization: ");
        printOptimal(1, n);
    }

    static void matrixChainOrder(int[] p, int n) {

        M = new int[n + 1][n + 1];
        S = new int[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            M[i][i] = 0;
        }

        for (int L = 2; L <= n; L++) {

            for (int i = 1; i <= n - L + 1; i++) {

                int j = i + L - 1;
                M[i][j] = Integer.MAX_VALUE;

                for (int k = i; k < j; k++) {

                    int cost = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];

                    if (cost < M[i][j]) {
                        M[i][j] = cost;
                        S[i][j] = k; // store split point
                    }
                }
            }
        }
    }

    static void printOptimal(int i, int j) {

        if (i == j) {
            System.out.print("A" + i);
            return;
        }

        System.out.print("(");

        printOptimal(i, S[i][j]); // left part
        printOptimal(S[i][j] + 1, j); // right part

        System.out.print(")");
    }
}