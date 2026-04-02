//MFT Simulation
#include <stdio.h>
#define MAX_TASKS 10
int main() {
    int totalMemory;
    int n;
    int taskSize[MAX_TASKS];
    int partitionSize;
    int i;
    int internalFragmentation = 0;
    printf("Enter total memory size (in KB): ");
    scanf("%d", &totalMemory);
    printf("Enter number of tasks: ");
    scanf("%d", &n);
    if (n > MAX_TASKS) {
        printf("Number of tasks exceeds system limit.\n");
        return 0;
    }
    partitionSize = totalMemory / n;
    printf("\nEach partition size = %d KB\n", partitionSize);
    for (i = 0; i < n; i++) {
        printf("Enter memory required for Task %d (in KB): ", i + 1);
        scanf("%d", &taskSize[i]);
    }
    printf("\n--- Memory Allocation Table ---\n");
    printf("Task\tTask Size\tPartition Size\tStatus\n");
    for (i = 0; i < n; i++) {
        if (taskSize[i] <= partitionSize) {
            printf("%d\t%d KB\t\t%d KB\t\tAllocated\n",
                   i + 1, taskSize[i], partitionSize);
            internalFragmentation += (partitionSize - taskSize[i]);
        } else {
            printf("%d\t%d KB\t\t%d KB\t\tNot Allocated\n",
                   i + 1, taskSize[i], partitionSize);
        }
    }
    printf("\nTotal Internal Fragmentation = %d KB\n", internalFragmentation);
    return 0;
}
