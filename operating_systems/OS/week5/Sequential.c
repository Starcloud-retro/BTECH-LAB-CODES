//  WEEK5 :: Sequential File Allocation Strategies
#include <stdio.h>

int main() {
    int f[50], i, st, len, j, c, k, count;

    // Initialize all blocks as free
    for (i = 0; i < 50; i++)
        f[i] = 0;

    printf("Sequential File Allocation Simulation\n");

    do {
        count = 0;
        printf("\nEnter starting block and length of file: ");
        scanf("%d %d", &st, &len);

        // Check if requested blocks are free
        for (k = st; k < (st + len); k++) {
            if (f[k] == 0)
                count++;
        }

        if (count == len) {
            // Allocate blocks
            for (j = st; j < (st + len); j++) {
                f[j] = 1;
                printf("Block %d -> Allocated\n", j);
            }
            printf("File successfully allocated.\n");
        } else {
            printf("File cannot be allocated (some blocks are already occupied).\n");
        }

        printf("\nDo you want to enter more files? (Yes=1 / No=0): ");
        scanf("%d", &c);

    } while (c == 1);

    return 0;
}