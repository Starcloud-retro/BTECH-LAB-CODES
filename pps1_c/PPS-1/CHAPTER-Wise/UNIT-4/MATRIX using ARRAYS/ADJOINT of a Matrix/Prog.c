#include <stdio.h>

// Function to get cofactor of matrix a[p][q] in temp[][]. n is current dimension of a[][].
void getCofactor(int a[5][5], int temp[5][5], int p, int q, int n) {
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

// Recursive function to find determinant of matrix a[][] of size n.
int determinant(int a[5][5], int n) {
    int D = 0; // Initialize result
    if (n == 1)
        return a[0][0];
    int temp[5][5]; // To store cofactors
    int sign = 1;  // To store sign multiplier
    for (int f = 0; f < n; f++) {
        getCofactor(a, temp, 0, f, n);
        D += sign * a[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
    return D;
}

// Function to calculate adjoint of a[][] and store in adj[][]
void adjoint(int a[5][5], int adj[5][5], int n) {
    if (n == 1) {
        adj[0][0] = 1;
        return;
    }
    int sign = 1, temp[5][5];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            getCofactor(a, temp, i, j, n);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (sign) * (determinant(temp, n - 1));
        }
    }
}

int main() {
    int n, i, j;
    int a[5][5], adj[5][5]; // Declare a 5x5 matrix and its adjoint

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

    // Calculate the adjoint
    adjoint(a, adj, n);

    // Print the adjoint
    printf("The adjoint of the matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}