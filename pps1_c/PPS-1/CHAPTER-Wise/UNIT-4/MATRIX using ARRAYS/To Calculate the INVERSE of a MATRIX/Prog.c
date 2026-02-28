#include <stdio.h>

#define MAX 5

// Function to get cofactor of matrix a[p][q] in temp[][]. n is current dimension of a[][].
void getCofactor(int a[MAX][MAX], int temp[MAX][MAX], int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // Copying only those elements which are not in given row and column
            if (row != p && col != q) {
                temp[i][j++] = a[row][col];
                // Row is filled, so increase row index and reset col index
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// Function to calculate determinant of matrix a[][]. n is current dimension of a[][].
int determinant(int a[MAX][MAX], int n) {
    int D = 0; // Initialize result
    if (n == 1)
        return a[0][0];
    int temp[MAX][MAX]; // To store cofactors
    int sign = 1;  // To store sign multiplier
    for (int f = 0; f < n; f++) {
        getCofactor(a, temp, 0, f, n);
        D += sign * a[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
    return D;
}

// Function to get adjoint of a[][]
void adjoint(int a[MAX][MAX], int adj[MAX][MAX], int n) {
    if (n == 1) {
        adj[0][0] = 1;
        return;
    }
    int sign = 1, temp[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            getCofactor(a, temp, i, j, n);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (sign) * (determinant(temp, n - 1));
        }
    }
}

// Function to calculate and display inverse of a[][].
int inverse(int a[MAX][MAX], float inverse[MAX][MAX], int n) {
    int det = determinant(a, n);
    if (det == 0) {
        printf("Singular matrix, can't find its inverse\n");
        return 0;
    }
    int adj[MAX][MAX];
    adjoint(a, adj, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse[i][j] = adj[i][j] / (float) det;
        }
    }
    return 1;
}

// Driver program
int main() {
    int n, i, j;
    int a[MAX][MAX]; // Declare a 5x5 matrix
    float inv[MAX][MAX]; // To store inverse matrix

    // Read the size of the matrix
    printf("Enter the order of the matrix (n x n): ");
    scanf("%d", &n);

    if (n > 5) {
        printf("The matrix size is too large. Please enter a size of 5 or less.\n");
        return 1;
    }

    // Read the elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Calculate the inverse
    if (inverse(a, inv, n)) {
        printf("The inverse of the matrix is:\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%0.2f ", inv[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}