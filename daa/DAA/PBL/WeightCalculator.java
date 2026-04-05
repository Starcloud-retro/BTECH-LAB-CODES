package com.satellite;

/**
 * Computes edge weights for the satellite communication network.
 *
 * Formula:  weight(u, v, t) = distance(u, v, t) + delay(u, v, t) + interference(t)
 *
 * WHY EACH TERM:
 *
 *   distance(u,v,t)    — Satellites move. The physical gap between two nodes
 *                         changes every time step. Longer gap = more costly link.
 *                         This is the primary dynamic variable.
 *
 *   delay(u,v,t)       — Signal travels at speed of light. delay = distance / c.
 *                         Kept as a separate term because in real systems it also
 *                         includes node processing time. Here: proportional to distance.
 *
 *   interference(t)    — Atmospheric noise, solar activity, link congestion.
 *                         Does not depend on which specific link — affects all links
 *                         differently with a random perturbation each time step.
 *                         This is what makes the problem genuinely unpredictable.
 *
 * The weight is scaled and rounded to integer values so it stays compatible
 * with the original Dijkstra implementation (which uses int[][] cost matrix).
 */
public class WeightCalculator {

    // Speed of light factor — purely a scaling constant for simulation
    private static final double SPEED_OF_LIGHT_FACTOR = 0.3;

    // Maximum interference added per edge per time step
    private static final double MAX_INTERFERENCE = 5.0;

    private final java.util.Random rng;

    public WeightCalculator(long seed) {
        this.rng = new java.util.Random(seed);
    }

    /**
     * Compute the integer weight for edge (u → v) at current positions.
     *
     * @param u    source node
     * @param v    destination node
     * @param time current time step (used for interference seed)
     * @return     integer edge weight
     */
    public int compute(SatelliteNode u, SatelliteNode v, int time) {
        double dist          = u.distanceTo(v);
        double delay         = dist * SPEED_OF_LIGHT_FACTOR;
        double interference  = rng.nextDouble() * MAX_INTERFERENCE;

        double raw = dist + delay + interference;

        // Scale to a readable integer range (10–99) for easy hand-tracing
        int scaled = (int) Math.round(raw * 3.5);
        return Math.max(10, Math.min(scaled, 99));
    }

    /**
     * Build a full cost matrix for the current node positions.
     * Only edges in the adjacency list get a weight; others stay at INF.
     *
     * @param nodes     array of all nodes
     * @param edges     list of [from, to] pairs that exist
     * @param INF       sentinel for no-edge
     * @param time      current time step
     * @return          n×n cost matrix (1-indexed like mam's Java code)
     */
    public int[][] buildCostMatrix(SatelliteNode[] nodes, int[][] edges,
                                   int INF, int time) {
        int n = nodes.length;
        int[][] cost = new int[n + 1][n + 1];

        // Fill with INF, diagonal = 0  (exactly as in mam's code)
        for (int i = 0; i <= n; i++) {
            java.util.Arrays.fill(cost[i], INF);
            if (i > 0) cost[i][i] = 0;
        }

        // Only the defined edges get real weights
        for (int[] edge : edges) {
            int from = edge[0];
            int to   = edge[1];
            int w    = compute(nodes[from - 1], nodes[to - 1], time);
            cost[from][to] = w;
            cost[to][from] = w;   // undirected network
        }

        return cost;
    }
}
