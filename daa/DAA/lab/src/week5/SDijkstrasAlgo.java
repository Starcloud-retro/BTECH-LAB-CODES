package week5;

import java.util.*;

public class SDijkstrasAlgo {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter number of vertices: ");
        int V = sc.nextInt();
        
        System.out.print("Enter number of edges: ");
        int E = sc.nextInt();
        
        int[][] graph = new int[V][V];
        
        System.out.println("Enter edges (source destination weight):");
        for (int i = 0; i < E; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            graph[u][v] = w;
            graph[v][u] = w;
        }
        
        System.out.print("Enter source vertex: ");
        int source = sc.nextInt();
        
        dijkstra(graph, V, source);
        
        sc.close();
    }
    
    static void dijkstra(int[][] graph, int V, int source) {
        
        int[] dist = new int[V];
        boolean[] visited = new boolean[V];
        int[] parent = new int[V];
        
        for (int i = 0; i < V; i++) {
            dist[i] = Integer.MAX_VALUE;
            visited[i] = false;
            parent[i] = -1;
        }
        
        dist[source] = 0;
        
        for (int count = 0; count < V; count++) {
            
            int u = findMinDistanceVertex(dist, visited, V);
            visited[u] = true;
            
            for (int v = 0; v < V; v++) {
                if (!visited[v] && graph[u][v] != 0 && 
                    dist[u] != Integer.MAX_VALUE &&
                    dist[u] + graph[u][v] < dist[v]) {
                    
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
        
        printSolution(dist, parent, V, source);
    }
    
    static int findMinDistanceVertex(int[] dist, boolean[] visited, int V) {
        
        int minDistance = Integer.MAX_VALUE;
        int minVertex = -1;
        
        for (int v = 0; v < V; v++) {
            if (!visited[v] && dist[v] < minDistance) {
                minDistance = dist[v];
                minVertex = v;
            }
        }
        
        return minVertex;
    }
    
    static void printSolution(int[] dist, int[] parent, int V, int source) {
        
        System.out.println("\nVertex\t\tDistance\tPath");
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
    
    static void printPath(int[] parent, int vertex, int source) {
        
        if (vertex == source) {
            System.out.print(source);
            return;
        }
        
        if (parent[vertex] != -1) {
            printPath(parent, parent[vertex], source);
            System.out.print(" → " + vertex);
        }
    }
}