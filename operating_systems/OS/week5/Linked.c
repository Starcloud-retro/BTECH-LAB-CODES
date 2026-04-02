//  WEEK5 :: Linked File Allocation Strategies
#include <stdio.h>

int main() {
    int f[50], p, i, st, len, j, c, a, count;

    // Initialize all blocks as free
    for (i = 0; i < 50; i++)
        f[i] = 0;

    printf("Linked File Allocation Simulation\n");

    // Pre-allocated blocks
    printf("Enter how many blocks are already allocated: ");
    scanf("%d", &p);

    printf("Enter the block numbers already allocated: ");
    for (i = 0; i < p; i++) {
        scanf("%d", &a);
        f[a] = 1;
    }

    do {
        printf("\nEnter starting block and length of file: ");
        scanf("%d %d", &st, &len);

        if (f[st] == 1) {
            printf("Starting block %d is already allocated.\n", st);
        } else {
            count = 0;
            // Check if enough free blocks exist
            for (j = st; j < (st + len); j++) {
                if (f[j] == 0)
                    count++;
            }

            if (count == len) {
                // Allocate blocks
                for (j = st; j < (st + len); j++) {
                    f[j] = 1;
                    if (j < st + len - 1)
                        printf("%d -> %d : Allocated\n", j, j + 1);
                    else
                        printf("%d -> NULL : Allocated\n", j);
                }
                printf("File successfully allocated using linked allocation.\n");
            } else {
                printf("File cannot be allocated (some blocks are already occupied).\n");
            }
        }

        printf("\nDo you want to enter more files? (Yes=1 / No=0): ");
        scanf("%d", &c);

    } while (c == 1);

    return 0;
}