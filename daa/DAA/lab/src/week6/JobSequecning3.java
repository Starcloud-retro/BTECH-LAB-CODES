
import java.util.*;

public class JobSequecning3 {

    // Job class
    static class Job {
        int jobNo;
        int profit;
        int deadline;
        int slotAssigned;
        String slotRange;

        Job(int jobNo, int profit, int deadline) {
            this.jobNo = jobNo;
            this.profit = profit;
            this.deadline = deadline;
            this.slotAssigned = -1;
            this.slotRange = "REJECTED";
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input number of jobs
        System.out.print("Enter the number of jobs: ");
        int n = sc.nextInt();

        Job[] jobs = new Job[n];

        // Input job details
        for (int i = 0; i < n; i++) {
            System.out.print("Enter the profit and deadline of job #" + (i + 1) + ": ");
            int profit = sc.nextInt();
            int deadline = sc.nextInt();
            jobs[i] = new Job(i + 1, profit, deadline);
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
        int[] slot = new int[maxDeadline];
        boolean[] slotFilled = new boolean[maxDeadline];

        // Schedule jobs
        int totalProfit = 0;
        @SuppressWarnings("unused")
        int jobCount = 0;

        for (int i = 0; i < n; i++) {
            // Find free slot from deadline-1 to 0
            for (int j = Math.min(maxDeadline - 1, jobs[i].deadline - 1); j >= 0; j--) {
                if (!slotFilled[j]) {
                    slot[j] = jobs[i].jobNo;
                    slotFilled[j] = true;
                    jobs[i].slotAssigned = j;
                    jobs[i].slotRange = "[" + j + " - " + (j + 1) + "]";
                    totalProfit += jobs[i].profit;
                    jobCount++;
                    break;
                }
            }
        }

        // Print output in required format
        System.out.println("\nJob-No\tPROFIT\tDEADLINE\tSLOT ALLOTTED");
        System.out.println();

        for (int i = 0; i < n; i++) {
            System.out.println(jobs[i].jobNo + "\t" +
                    jobs[i].profit + "\t" +
                    jobs[i].deadline + "\t\t" +
                    jobs[i].slotRange);
        }

        // Print slot assignment array
        System.out.print("Slot assignment Array\n");
        for (int i = 0; i < maxDeadline; i++) {
            if (slotFilled[i]) {
                System.out.print(slot[i] + " ");
            }
        }

        System.out.println("\nTotal Profit: " + totalProfit);
    }
}
