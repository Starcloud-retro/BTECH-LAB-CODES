package com.satellite;

import java.util.*;

/**
 * Dijkstra's algorithm — faithful to mam's Java implementation.
 *
 * The core logic (select[], distance[], pred[], min-distance loop,
 * relaxation loop) is identical to the reference code.
 *
 * The only addition: a StepTrace is recorded after each iteration
 * so the frontend can replay the algorithm step by step.
 */
public class DijkstraEngine {

    public static final int INF = 999;

    // ── Result containers ──────────────────────────────────────

    /** Full result of one Dijkstra run */
    public static class Result {
        public int[]        distance;
        public int[]        pred;
        public List<Step>   steps;      // one entry per iteration
        public List<Integer> path;      // shortest path from source to node n

        public Result(int[] distance, int[] pred, List<Step> steps, List<Integer> path) {
            this.distance = distance;
            this.pred     = pred;
            this.steps    = steps;
            this.path     = path;
        }
    }

    /** Snapshot of algorithm state after one iteration */
    public static class Step {
        public int   iterationNumber;
        public int   selectedNode;      // the node finalized this iteration
        public int[] distanceSnapshot; // copy of distance[] after this iteration
        public int[] predSnapshot;     // copy of pred[] after this iteration
        public List<int[]> relaxedEdges; // [from, to, oldDist, newDist] for updated edges

        public Step(int iter, int selected, int[] dist, int[] pred, List<int[]> relaxed) {
            this.iterationNumber  = iter;
            this.selectedNode     = selected;
            this.distanceSnapshot = dist.clone();
            this.predSnapshot     = pred.clone();
            this.relaxedEdges     = relaxed;
        }
    }

    // ── Core algorithm ─────────────────────────────────────────

    /**
     * Run Dijkstra from source on the given cost matrix.
     * n = number of vertices (1-indexed, matching mam's code).
     */
    public static Result run(int[][] cost, int n, int source) {
        int[]     distance = new int[n + 1];
        int[]     pred     = new int[n + 1];
        boolean[] select   = new boolean[n + 1];

        // ── Initialization (exact copy of mam's code) ──
        Arrays.fill(select, false);
        for (int i = 1; i <= n; i++) {
            distance[i] = cost[source][i];
            pred[i]     = source;
        }
        distance[source] = 0;
        select[source]   = true;

        List<Step> steps = new ArrayList<>();

        // Record initial state as step 0
        steps.add(new Step(0, source, distance, pred, new ArrayList<>()));

        int count = 1;

        // ── Main loop (exact copy of mam's code) ──
        while (count < n) {
            int mindistance = INF;
            int chosen      = -1;

            // Find minimum-distance unvisited vertex
            for (int i = 1; i <= n; i++) {
                if (distance[i] < mindistance && !select[i]) {
                    mindistance = distance[i];
                    chosen      = i;
                }
            }

            if (chosen == -1) break; // graph is disconnected

            select[chosen] = true;

            List<int[]> relaxed = new ArrayList<>();

            // Relax neighbors of chosen
            for (int i = 1; i <= n; i++) {
                if (!select[i] && mindistance + cost[chosen][i] < distance[i]) {
                    int oldDist = distance[i];
                    distance[i] = mindistance + cost[chosen][i];
                    pred[i]     = chosen;
                    relaxed.add(new int[]{chosen, i, oldDist, distance[i]});
                }
            }

            steps.add(new Step(count, chosen, distance, pred, relaxed));
            count++;
        }

        // ── Reconstruct path to last node (node n) ──
        List<Integer> path = new ArrayList<>();
        int j = n;
        while (j != source) {
            path.add(0, j);
            j = pred[j];
        }
        path.add(0, source);

        return new Result(distance, pred, steps, path);
    }

    /** Extract path from source to a specific target using pred[] */
    public static List<Integer> getPath(int[] pred, int source, int target) {
        List<Integer> path = new ArrayList<>();
        int j = target;
        while (j != source) {
            path.add(0, j);
            if (pred[j] == j) break; // safety: disconnected
            j = pred[j];
        }
        path.add(0, source);
        return path;
    }
}
