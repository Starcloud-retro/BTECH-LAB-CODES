package com.satellite;

/**
 * Defines the 5-node satellite network used in the simulation.
 *
 * Nodes:
 *   1 — Ground Station (stationary)
 *   2 — SAT-A  (low orbit, fast)
 *   3 — SAT-B  (low orbit, medium speed)
 *   4 — SAT-C  (high orbit, slow)
 *   5 — SAT-D  (high orbit, very slow) — destination
 *
 * Edges (communication links that always exist):
 *   1-2, 1-3, 2-3, 2-4, 3-4, 3-5, 4-5
 *
 * The topology is fixed. Only the weights change as satellites move.
 * This keeps the graph traceable by hand while still showing path changes.
 */
public class NetworkBuilder {

    public static SatelliteNode[] buildNodes() {
        return new SatelliteNode[] {
            // id, name,         orbitRadius, initialAngle, angularSpeed, isGround
            new SatelliteNode(1, "GND",   0.0,  0.0,   0.0,  true),   // Ground Station
            new SatelliteNode(2, "SAT-A", 30.0,  0.0,  15.0, false),  // fast inner orbit
            new SatelliteNode(3, "SAT-B", 30.0, 90.0,  10.0, false),  // medium inner orbit
            new SatelliteNode(4, "SAT-C", 55.0, 45.0,   6.0, false),  // slow outer orbit
            new SatelliteNode(5, "SAT-D", 55.0,200.0,   4.0, false),  // destination (outer)
        };
    }

    /**
     * Edges as [from, to] pairs (1-indexed).
     * Both directions are added by WeightCalculator (undirected).
     */
    public static int[][] buildEdges() {
        return new int[][] {
            {1, 2},   // Ground → SAT-A
            {1, 3},   // Ground → SAT-B
            {2, 3},   // SAT-A  → SAT-B
            {2, 4},   // SAT-A  → SAT-C
            {3, 4},   // SAT-B  → SAT-C
            {3, 5},   // SAT-B  → SAT-D
            {4, 5},   // SAT-C  → SAT-D
        };
    }

    public static String[] nodeNames() {
        return new String[]{"", "GND", "SAT-A", "SAT-B", "SAT-C", "SAT-D"};
    }
}
