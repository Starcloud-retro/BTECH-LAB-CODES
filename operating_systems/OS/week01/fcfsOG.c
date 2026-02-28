#include <stdio.h>

struct process {
    int pid;
    int at;     // ← Arrival Time (NEW)
    int bt;     // Burst Time
    int wt;     // Waiting Time
    int tt;     // Turnaround Time
    int ct;     // Completion Time (optional but useful)
};

int main() {
    struct process p[100];
    int n, i;
    float totwt = 0, tottt = 0;
    float avgwt, avgtt;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter details for each process:\n");
    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nProcess P%d:\n", p[i].pid);
        printf("  Arrival Time : ");
        scanf("%d", &p[i].at);
        printf("  Burst Time   : ");
        scanf("%d", &p[i].bt);
    }

    // Very important: sort processes by arrival time (for realistic FCFS)
    // (you can skip sorting only if you're 100% sure input is already in arrival order)
    
    // Simple bubble sort by arrival time
    for(i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(p[j].at > p[j+1].at) {
                struct process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    // FCFS calculation
    int current_time = 0;

    for(i = 0; i < n; i++) {
        // If CPU is idle, move to next arrival
        if(current_time < p[i].at)
            current_time = p[i].at;

        p[i].wt = current_time - p[i].at;
        p[i].ct = current_time + p[i].bt;
        p[i].tt = p[i].ct - p[i].at;     // or = wt + bt

        current_time = p[i].ct;
        
        totwt += p[i].wt;
        tottt += p[i].tt;
    }

    avgwt = totwt / n;
    avgtt = tottt / n;

    // ───────────────────────────────────────────────
    printf("\n  ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐\n");
    printf("  │ Process │ Arrival │  Burst  │  Wait   │ TurnArd │ Complete│\n");
    printf("  ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤\n");

    for(i = 0; i < n; i++) {
        printf("  │   P%-2d   │   %3d   │   %3d   │   %3d   │   %3d   │   %3d   │\n",
               p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tt, p[i].ct);
    }
    printf("  └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘\n");

    printf("\nAverage Waiting Time    = %.2f\n", avgwt);
    printf("Average Turnaround Time = %.2f\n\n", avgtt);

    return 0;
}
