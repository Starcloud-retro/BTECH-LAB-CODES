//  WEEK5 :: Indexed File Allocation Strategies
#include <stdio.h>
#include <stdlib.h>

int main() {
    int f[50], index[50], i, n, j, k, ind, c, count;

    // Initialize all blocks as free
    for (i = 0; i < 50; i++)
        f[i] = 0;

    printf("Indexed File Allocation Simulation\n");

    do {
        printf("\nEnter the index block: ");
        scanf("%d", &ind);

        if (f[ind] == 1) {
            printf("Index block %d is already allocated.\n", ind);
            continue;
        }

        printf("Enter number of blocks needed for index %d: ", ind);
        scanf("%d", &n);

        count = 0;
        printf("Enter the block numbers:\n");
        for (i = 0; i < n; i++) {
            scanf("%d", &index[i]);
            if (f[index[i]] == 0)
                count++;
        }

        if (count == n) {
            // Allocate index block and data blocks
            f[ind] = 1;
            for (j = 0; j < n; j++)
                f[index[j]] = 1;

            printf("File allocated using indexed allocation.\n");
            printf("Index Block: %d\n", ind);
            for (k = 0; k < n; k++)
                printf("%d -> %d : Allocated\n", ind, index[k]);
        } else {
            printf("Some blocks are already allocated. File cannot be allocated.\n");
        }

        printf("\nDo you want to enter more files? (Yes=1 / No=0): ");
        scanf("%d", &c);

    } while (c == 1);

    return 0;
}