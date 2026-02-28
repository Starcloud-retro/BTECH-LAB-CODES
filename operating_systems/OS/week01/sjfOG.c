#include <stdio.h>

struct process {
    int pid;
    int at;     // Arrival Time
    int bt;     // Burst Time
    int wt;     // Waiting Time
    int tt;     // Turnaround Time
    int ct;     // Completion Time
};

int main() {
    struct process p[100], temp;
    int n, i, j;
    float totwt = 0, tottt = 0;
    float avgwt, avgtt;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter details:\n");
    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("P%d → Arrival time: ", p[i].pid);
        scanf("%d", &p[i].at);
        printf("P%d → Burst time  : ", p[i].pid);
        scanf("%d", &p[i].bt);
    }

    // Sort by arrival time first (very important!)
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(p[j].at > p[j+1].at) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    int current_time = 0;
    int completed = 0;

    while(completed < n) {
        int shortest = -1;
        int min_bt = 999999;

        // Find process with shortest burst time among arrived processes
        for(i = 0; i < n; i++) {
            if(p[i].at <= current_time && p[i].bt > 0 && p[i].bt < min_bt) {
                min_bt = p[i].bt;
                shortest = i;
            }
        }

        if(shortest == -1) {
            // No process is ready → CPU idle
            current_time++;
            continue;
        }

        // Execute the shortest job
        current_time += p[shortest].bt;
        p[shortest].ct = current_time;
        p[shortest].tt = p[shortest].ct - p[shortest].at;
        p[shortest].wt = p[shortest].tt - p[shortest].bt;
        p[shortest].bt = 0;  // Mark as completed
        completed++;

        totwt += p[shortest].wt;
        tottt += p[shortest].tt;
    }

    avgwt = totwt / n;
    avgtt = tottt / n;

    printf("\n  Process   AT    BT    CT    WT    TAT\n");
    printf("  ───────────────────────────────────────\n");
    for(i = 0; i < n; i++) {
        printf("     P%-2d   %3d   %3d   %3d   %3d   %3d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tt);
    }

    printf("\nAverage Waiting Time    = %.2f\n", avgwt);
    printf("Average Turnaround Time = %.2f\n", avgtt);

    return 0;
}
