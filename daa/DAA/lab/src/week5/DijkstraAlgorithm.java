package week5;

import java.util.*;

public class DijkstraAlgorithm {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // INPUT: Number of vertices
        System.out.print("Enter number of vertices: ");
        int V = sc.nextInt();
        
        // INPUT: Number of edges
        System.out.print("Enter number of edges: ");
        int E = sc.nextInt();
        
        // Create adjacency matrix for the graph
        // graph[i][j] = weight of edge from i to j
        // graph[i][j] = 0 means no edge
        int[][] graph = new int[V][V];
        
        // INPUT: All edges with weights
        System.out.println("Enter edges (source destination weight):");
        for (int i = 0; i < E; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            
            // For undirected graph, add edge both ways
            graph[u][v] = w;
            graph[v][u] = w;
            
            // For directed graph, use only: graph[u][v] = w;
        }
        
        // INPUT: Source vertex
        System.out.print("\nEnter source vertex: ");
        int source = sc.nextInt();
        
        // Run Dijkstra's algorithm
        dijkstra(graph, V, source);
        
        sc.close();
    }
    
    /**
     * DIJKSTRA'S ALGORITHM
     * Finds shortest path from source to all other vertices
     * 
     * @param graph - Adjacency matrix representation
     * @param V - Number of vertices
     * @param source - Starting vertex
     */
    static void dijkstra(int[][] graph, int V, int source) {
        
        // STEP 1: INITIALIZATION
        
        // Distance array: stores shortest distance from source to each vertex
        int[] dist = new int[V];
        
        // Visited array: tracks which vertices are processed
        boolean[] visited = new boolean[V];
        
        // Parent array: stores the path (previous vertex in shortest path)
        int[] parent = new int[V];
        
        // Initialize all distances to infinity
        for (int i = 0; i < V; i++) {
            dist[i] = Integer.MAX_VALUE;
            visited[i] = false;
            parent[i] = -1;
        }
        
        // Distance to source is 0 (starting point)
        dist[source] = 0;
        
        System.out.println("\n=== DIJKSTRA'S ALGORITHM ===");
        System.out.println("Finding shortest paths from vertex " + source + "\n");
        
        // STEP 2: MAIN LOOP - Process all vertices
        for (int count = 0; count < V; count++) {
            
            // STEP 2a: FIND MINIMUM DISTANCE VERTEX
            // Among all unvisited vertices, find the one with minimum distance
            int u = findMinDistanceVertex(dist, visited, V);
            
            // STEP 2b: MARK AS VISITED
            // Mark the selected vertex as processed
            visited[u] = true;
            
            System.out.println("Processing vertex " + u + " (distance: " + 
                               (dist[u] == Integer.MAX_VALUE ? "∞" : dist[u]) + ")");
            
            // STEP 2c: RELAXATION STEP
            // Update distances of all adjacent vertices of the selected vertex
            for (int v = 0; v < V; v++) {
                
                // Check if:
                // 1. v is not visited yet
                // 2. There is an edge from u to v (weight > 0)
                // 3. Path through u to v is shorter than current distance to v
                // 4. Distance to u is not infinity
                
                if (!visited[v] && 
                    graph[u][v] != 0 && 
                    dist[u] != Integer.MAX_VALUE &&
                    dist[u] + graph[u][v] < dist[v]) {
                    
                    // Found a shorter path to v through u
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                    
                    System.out.println("  → Updated distance to vertex " + v + 
                                       ": " + dist[v] + " (via " + u + ")");
                }
            }
            System.out.println();
        }
        
        // STEP 3: DISPLAY RESULTS
        printSolution(dist, parent, V, source);
    }
    
    /**
     * HELPER FUNCTION: Find vertex with minimum distance
     * Searches through all unvisited vertices
     * 
     * @param dist - Distance array
     * @param visited - Visited array
     * @param V - Number of vertices
     * @return Index of vertex with minimum distance
     */
    static int findMinDistanceVertex(int[] dist, boolean[] visited, int V) {
        
        int minDistance = Integer.MAX_VALUE;
        int minVertex = -1;
        
        // Check all vertices
        for (int v = 0; v < V; v++) {
            // If vertex is not visited and has smaller distance
            if (!visited[v] && dist[v] < minDistance) {
                minDistance = dist[v];
                minVertex = v;
            }
        }
        
        return minVertex;
    }
    
    /**
     * HELPER FUNCTION: Print the solution
     * Shows shortest distances and paths from source
     * 
     * @param dist - Array of shortest distances
     * @param parent - Array of parents for path reconstruction
     * @param V - Number of vertices
     * @param source - Source vertex
     */
    static void printSolution(int[] dist, int[] parent, int V, int source) {
        
        System.out.println("=== SHORTEST PATHS FROM VERTEX " + source + " ===\n");
        System.out.println("Vertex\t\tDistance\tPath");
        System.out.println("----------------------------------------");
        
        for (int i = 0; i < V; i++) {
            System.out.print(i + "\t\t");
            
            if (dist[i] == Integer.MAX_VALUE) {
                System.out.println("∞\t\tNo path");
            } else {
                System.out.print(dist[i] + "\t\t");
                printPath(parent, i, source);
                System.out.println();
            }
        }
    }
    
    /**
     * HELPER FUNCTION: Print path from source to destination
     * Uses recursion to backtrack through parent array
     * 
     * @param parent - Parent array
     * @param vertex - Current vertex
     * @param source - Source vertex
     */
    static void printPath(int[] parent, int vertex, int source) {
        
        // Base case: reached source
        if (vertex == source) {
            System.out.print(source);
            return;
        }
        
        // Recursive case: print path to parent first
        if (parent[vertex] != -1) {
            printPath(parent, parent[vertex], source);
            System.out.print(" → " + vertex);
        }
    }
}