#include <stdio.h>

struct process {
    int pid;
    int at;      // Arrival Time
    int bt;      // Burst Time
    int prior;   // Priority (lower number = higher priority)
    int wt;      // Waiting Time
    int tt;      // Turnaround Time
    int ct;      // Completion Time
};

int main() {
    struct process p[100], temp;
    int n, i, j;
    float totwt = 0, tottt = 0;
    float avgwt, avgtt;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter process details:\n");
    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("P%-2d  Arrival time : ", p[i].pid);
        scanf("%d", &p[i].at);
        printf("P%-2d  Burst time   : ", p[i].pid);
        scanf("%d", &p[i].bt);
        printf("P%-2d  Priority     : ", p[i].pid);
        scanf("%d", &p[i].prior);
        printf("\n");
    }

    // Sort by arrival time first
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

    printf("\n  Gantt Chart / Execution Order:\n  ");
    
    while(completed < n) {
        int highest_priority = -1;
        int selected = -1;

        // Find process with highest priority (lowest number) among arrived
        for(i = 0; i < n; i++) {
            if(p[i].at <= current_time && p[i].bt > 0) {
                if(highest_priority == -1 || p[i].prior < p[highest_priority].prior) {
                    highest_priority = p[i].prior;
                    selected = i;
                }
            }
        }

        if(selected == -1) {
            // No process is ready → idle
            current_time++;
            printf("(idle) ");
            continue;
        }

        // Execute selected process completely (non-preemptive)
        current_time += p[selected].bt;
        
        p[selected].ct = current_time;
        p[selected].tt = p[selected].ct - p[selected].at;
        p[selected].wt = p[selected].tt - p[selected].bt;
        p[selected].bt = 0;  // completed

        printf("P%d ", p[selected].pid);
        completed++;

        totwt += p[selected].wt;
        tottt += p[selected].tt;
    }

    printf("\n\n");

    // Result Table
    printf("  PID   AT   BT   Priority   CT    WT    TAT\n");
    printf("  ──────────────────────────────────────────\n");
    for(i = 0; i < n; i++) {
        printf("   %-2d  %3d  %3d     %3d      %3d   %3d   %3d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].prior, 
               p[i].ct, p[i].wt, p[i].tt);
    }

    avgwt = totwt / n;
    avgtt = tottt / n;

    printf("\nAverage Waiting Time    = %.2f\n", avgwt);
    printf("Average Turnaround Time = %.2f\n\n", avgtt);

    return 0;
}
