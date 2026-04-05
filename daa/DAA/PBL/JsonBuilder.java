package com.satellite;

import java.util.List;

/**
 * Minimal JSON builder — no external libraries.
 * Keeps the project dependency-free and easy to explain.
 */
public class JsonBuilder {

    /** Serialize the full simulation state for one time step */
    public static String simulationState(
            SatelliteNode[] nodes,
            int[][] edges,
            int[][] costMatrix,
            DijkstraEngine.Result result,
            int timeStep,
            List<Integer> prevPath,
            String[] names,
            int n) {

        StringBuilder sb = new StringBuilder();
        sb.append("{\n");
        sb.append("  \"timeStep\": ").append(timeStep).append(",\n");

        // ── nodes ──
        sb.append("  \"nodes\": [\n");
        for (int i = 0; i < nodes.length; i++) {
            SatelliteNode nd = nodes[i];
            sb.append("    {")
              .append("\"id\":").append(nd.id).append(",")
              .append("\"name\":\"").append(nd.name).append("\",")
              .append("\"x\":").append(String.format("%.2f", nd.x())).append(",")
              .append("\"y\":").append(String.format("%.2f", nd.y())).append(",")
              .append("\"angle\":").append(String.format("%.1f", nd.angleDegrees)).append(",")
              .append("\"isGround\":").append(nd.isGroundStation)
              .append("}");
            if (i < nodes.length - 1) sb.append(",");
            sb.append("\n");
        }
        sb.append("  ],\n");

        // ── edges with current weights ──
        sb.append("  \"edges\": [\n");
        int[][] edgeDefs = NetworkBuilder.buildEdges();
        for (int i = 0; i < edgeDefs.length; i++) {
            int from = edgeDefs[i][0];
            int to   = edgeDefs[i][1];
            int w    = costMatrix[from][to];
            sb.append("    {")
              .append("\"from\":").append(from).append(",")
              .append("\"to\":").append(to).append(",")
              .append("\"weight\":").append(w)
              .append("}");
            if (i < edgeDefs.length - 1) sb.append(",");
            sb.append("\n");
        }
        sb.append("  ],\n");

        // ── distance array ──
        sb.append("  \"distance\": [");
        for (int i = 1; i <= n; i++) {
            sb.append(result.distance[i]);
            if (i < n) sb.append(",");
        }
        sb.append("],\n");

        // ── pred array ──
        sb.append("  \"pred\": [");
        for (int i = 1; i <= n; i++) {
            sb.append(result.pred[i]);
            if (i < n) sb.append(",");
        }
        sb.append("],\n");

        // ── current shortest path (GND → SAT-D) ──
        sb.append("  \"shortestPath\": [");
        for (int i = 0; i < result.path.size(); i++) {
            sb.append(result.path.get(i));
            if (i < result.path.size() - 1) sb.append(",");
        }
        sb.append("],\n");

        // ── path changed flag ──
        boolean changed = prevPath != null && !prevPath.equals(result.path);
        sb.append("  \"pathChanged\": ").append(changed).append(",\n");

        // ── algorithm steps for step-by-step mode ──
        sb.append("  \"steps\": [\n");
        List<DijkstraEngine.Step> steps = result.steps;
        for (int s = 0; s < steps.size(); s++) {
            DijkstraEngine.Step step = steps.get(s);
            sb.append("    {\n");
            sb.append("      \"iteration\": ").append(step.iterationNumber).append(",\n");
            sb.append("      \"selectedNode\": ").append(step.selectedNode).append(",\n");
            sb.append("      \"selectedName\": \"").append(names[step.selectedNode]).append("\",\n");

            sb.append("      \"distance\": [");
            for (int i = 1; i <= n; i++) {
                int d = step.distanceSnapshot[i];
                sb.append(d == DijkstraEngine.INF ? "999" : d);
                if (i < n) sb.append(",");
            }
            sb.append("],\n");

            sb.append("      \"pred\": [");
            for (int i = 1; i <= n; i++) {
                sb.append(step.predSnapshot[i]);
                if (i < n) sb.append(",");
            }
            sb.append("],\n");

            sb.append("      \"relaxed\": [");
            List<int[]> relaxed = step.relaxedEdges;
            for (int r = 0; r < relaxed.size(); r++) {
                int[] rel = relaxed.get(r);
                sb.append("{\"from\":").append(rel[0])
                  .append(",\"to\":").append(rel[1])
                  .append(",\"oldDist\":").append(rel[2])
                  .append(",\"newDist\":").append(rel[3]).append("}");
                if (r < relaxed.size() - 1) sb.append(",");
            }
            sb.append("]\n");

            sb.append("    }");
            if (s < steps.size() - 1) sb.append(",");
            sb.append("\n");
        }
        sb.append("  ]\n");

        sb.append("}");
        return sb.toString();
    }
}
