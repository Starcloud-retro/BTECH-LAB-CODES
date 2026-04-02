package week4;

import java.util.*;

public class PrimsAlgorithm {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Input number of vertices
        System.out.print("Enter number of vertices: ");
        int V = sc.nextInt();
        
        // Input number of edges
        System.out.print("Enter number of edges: ");
        int E = sc.nextInt();
        
        // Create adjacency matrix to store graph
        int[][] graph = new int[V][V];
        
        // Initialize all edges with infinity (no connection)
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                graph[i][j] = Integer.MAX_VALUE;
            }
        }
        
        // Input edges
        System.out.println("Enter edges (source destination weight):");
        for (int i = 0; i < E; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            
            // Undirected graph - add edge both ways
            graph[u][v] = w;
            graph[v][u] = w;
        }
        
        // Run Prim's algorithm
        primsAlgorithm(graph, V);
        
        sc.close();
    }
    
    static void primsAlgorithm(int[][] graph, int V) {
        // Array to track which vertices are included in MST
        boolean[] visited = new boolean[V];
        
        // Array to store minimum weight to reach each vertex
        int[] minWeight = new int[V];
        
        // Array to store parent of each vertex in MST
        int[] parent = new int[V];
        
        // Initialize all weights to infinity
        for (int i = 0; i < V; i++) {
            minWeight[i] = Integer.MAX_VALUE;
        }
        
        // Start from vertex 0
        minWeight[0] = 0;
        parent[0] = -1;
        
        System.out.println("\n=== PRIM'S ALGORITHM ===");
        System.out.println("Edges in MST:");
        
        int totalWeight = 0;
        
        // Process all vertices
        for (int count = 0; count < V; count++) {
            
            // STEP 1: Find the vertex with minimum weight that's not visited
            int minVertex = -1;
            int minValue = Integer.MAX_VALUE;
            
            for (int v = 0; v < V; v++) {
                if (!visited[v] && minWeight[v] < minValue) {
                    minValue = minWeight[v];
                    minVertex = v;
                }
            }
            
            // STEP 2: Mark this vertex as visited (add to MST)
            visited[minVertex] = true;
            
            // Print the edge (except for starting vertex)
            if (parent[minVertex] != -1) {
                System.out.println(parent[minVertex] + " -- " + minVertex + 
                                   "  (Weight: " + minWeight[minVertex] + ")");
                totalWeight += minWeight[minVertex];
            }
            
            // STEP 3: Update weights of adjacent vertices
            for (int v = 0; v < V; v++) {
                // If vertex is not visited, there's an edge, and weight is smaller
                if (!visited[v] && 
                    graph[minVertex][v] != Integer.MAX_VALUE && 
                    graph[minVertex][v] < minWeight[v]) {
                    
                    minWeight[v] = graph[minVertex][v];
                    parent[v] = minVertex;
                }
            }
        }
        
        System.out.println("\nTotal MST Weight: " + totalWeight);
    }
}
