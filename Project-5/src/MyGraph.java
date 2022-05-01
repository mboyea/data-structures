
/**
 * class MyGraph. Will use Matrix to represent a simple weighted directed graph. There is no loop at vertex.
 * No more than one edge from vertex i to another vertex j. The vertices are numbered as 1, 2, ..., n
 * The graph with n vertices is reprented by an (n+1) by (n+1) matrix with row 0 and column 0 unused.
 * If there is an edge from vertex i to vertex j (i != j), then entry on row i column j of the matrix will 
 * be 1. If there is no edge between vertex i to vertex j (i != j), then the entry on row i column j of the 
 * matrix will be Integer.MAX_VALUE
 * 
 * @author Hong Biao Zeng
 * @version Dec 12, 2015
 */
import java.util.*;
public class MyGraph
{
    private int[][] graph;
    private int numberOfVertices;
    
    /**
     * create a graph with given number of vertices with no edges
     * @param numberOfVertices number of vertices of the graph
     */
    public MyGraph(int numberOfVertices){
        this.numberOfVertices = numberOfVertices;
        graph = new int[numberOfVertices+1][numberOfVertices+1];
    }
    
    /**
     * create a graph with given matrix representation
     * @param graph The matrix representation on the given graph. Assume column 0 and row 0 are not used
     */
    public MyGraph(int [][] graph){
        this.graph = graph;
        // change any 0 to infinity if the 0 is not on diagonal
        for(int i = 1; i < graph.length; i++){
            for(int j = 1; j < graph.length; j++){
                if(i == j) graph[i][j] = 0;
                else if(i != j && graph[i][j] == 0)
                    graph[i][j] = Integer.MAX_VALUE;
            }
        }
        numberOfVertices = graph.length - 1; 
    }
    
    /**
     * return a String that represent the vertices in order if the BFS algorithm is used to traversal the graph
     * starting from the given vertex. If the startVertex not exists, return an error message
     * @param startVertex The vertex where the traversal starts
     * @return A String that describes the vertices visited in order
     */
    public String bfs(int startVertex){
        String path = "";
        // case: invalid startVertex
        if (startVertex < 1 || startVertex > numberOfVertices) {
            path = "Error: invalid startVertex";
            return path;
        }
        // insert startVertex into searchQueue
        Queue<Integer> searchQueue = new LinkedList<Integer>();
        searchQueue.add(startVertex);
        // insert startVertex into discoveredNodes
        Set<Integer> discoveredVertexes = new HashSet<Integer>();
        discoveredVertexes.add(startVertex);
        // while searchQueue has remaining vertices
        int targetVertex;
        while (!searchQueue.isEmpty()) {
            // get the next targetVertex
            targetVertex = searchQueue.poll();
            // add targetVertex to the path
            path += Integer.toString(targetVertex) + " ";
            // for every vertex
            for (int i = 1; i <= numberOfVertices; i++) {
                // if vertex is adjacent to targetVertex
                if (graph[targetVertex][i] != Integer.MAX_VALUE) {
                    // if the adjacent vertex is not in discoveredVertexes
                    if (!discoveredVertexes.contains(i)) {
                        // add the adjacent vertex to discoveredVertexes and searchQueue
                        searchQueue.add(i);
                        discoveredVertexes.add(i);
                    }
                }
            }
        }
        return path;
    }
    
    /**
     * return a String that represents the vertices in order if the DFS algorithm is used to traversal the graph
     * starting from the given vertex. If the startVertex not exist, return an error message
     * @param startVertex The vertex where the traversal starts
     * @return An ArrayList of Integer that represents the vertices visited in order
     */
    public String dfs(int startVertex){
        String path = "";
        // case: invalid startVertex
        if (startVertex < 1 || startVertex > numberOfVertices) {
            path = "Error: invalid startVertex";
            return path;
        }
        // insert startVertex into searchStack
        Stack<Integer> searchStack = new Stack<Integer>();
        searchStack.add(startVertex);
        // create discoveredNodes
        Set<Integer> discoveredVertices = new HashSet<Integer>();
        // while searchStack has remaining vertices
        int targetVertex;
        while (!searchStack.isEmpty()) {
            // get the next targetVertex
            targetVertex = searchStack.pop();
            // if targetVertex is not in DiscoveredVertices
            if (!discoveredVertices.contains(targetVertex)) {
                // add targetVertex to the path
                path += Integer.toString(targetVertex) + " ";
                // add targetVertex to DiscoveredVertices
                discoveredVertices.add(targetVertex);
                // for every vertex
                for (int i = 1; i <= numberOfVertices; i++) {
                    // if vertex is adjacent to targetVertex
                    if (graph[targetVertex][i] != Integer.MAX_VALUE) {
                        searchStack.add(i);
                    }
                }
            }
        }
        return path;
    }
}
