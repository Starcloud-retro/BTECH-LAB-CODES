package week6;

import java.util.*;

public class JobSequencing {
    
    // Job class
    static class Job {
        char id;
        int deadline;
        int profit;
        
        Job(char id, int deadline, int profit) {
            this.id = id;
            this.deadline = deadline;
            this.profit = profit;
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Input number of jobs
        System.out.print("Enter number of jobs: ");
        int n = sc.nextInt();
        
        Job[] jobs = new Job[n];
        
        // Input job details
        System.out.println("Enter job details (ID Deadline Profit):");
        for (int i = 0; i < n; i++) {
            char id = sc.next().charAt(0);
            int deadline = sc.nextInt();
            int profit = sc.nextInt();
            jobs[i] = new Job(id, deadline, profit);
        }
        
        // Run job sequencing
        jobSequencing(jobs, n);
        
        sc.close();
    }
    
    static void jobSequencing(Job[] jobs, int n) {
        
        // Sort jobs by profit (descending)
        Arrays.sort(jobs, (a, b) -> b.profit - a.profit);
        
        // Find maximum deadline
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            if (jobs[i].deadline > maxDeadline) {
                maxDeadline = jobs[i].deadline;
            }
        }
        
        // Create slot array
        char[] slot = new char[maxDeadline];
        boolean[] slotFilled = new boolean[maxDeadline];
        
        for (int i = 0; i < maxDeadline; i++) {
            slot[i] = '-';
            slotFilled[i] = false;
        }
        
        // Schedule jobs
        int totalProfit = 0;
        int jobCount = 0;
        
        for (int i = 0; i < n; i++) {
            // Find free slot from deadline-1 to 0
            for (int j = Math.min(maxDeadline - 1, jobs[i].deadline - 1); j >= 0; j--) {
                if (!slotFilled[j]) {
                    slot[j] = jobs[i].id;
                    slotFilled[j] = true;
                    totalProfit += jobs[i].profit;
                    jobCount++;
                    break;
                }
            }
        }
        
        // Print result
        System.out.println("\n=== JOB SEQUENCING RESULT ===");
        System.out.print("Scheduled Jobs: ");
        for (int i = 0; i < maxDeadline; i++) {
            if (slot[i] != '-') {
                System.out.print(slot[i] + " ");
            }
        }
        System.out.println("\nTotal Jobs: " + jobCount);
        System.out.println("Total Profit: " + totalProfit);
    }
}

