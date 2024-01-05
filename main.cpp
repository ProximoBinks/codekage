#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<list<int>> adj; // Adjacency lists

    // Utility function for Depth First Search (DFS)
    // Overall Time Complexity: O(|V| + |E|) for a call on all vertices
    void DFSUtil(int v, vector<bool> &visited) {
        // Mark the current node as visited and print it
        // Time Complexity: O(1)
        visited[v] = true;
        cout << v << " ";

        // Recur for all the vertices adjacent to this vertex
        // Time Complexity: Sum of the degrees of all vertices = O(|E|)
        for (int adjVertex : adj[v]) {
            if (!visited[adjVertex]) {
                DFSUtil(adjVertex, visited); // Recursively call DFS on adjacent vertices
                // Each vertex is visited exactly once due to the visited check, so the total
                // complexity over all calls to DFSUtil is O(|V|) for the vertices.
                // Each edge is explored in the adjacency lists of its vertices, so total
                // complexity over all calls to DFSUtil is O(|E|) for the edges.
            }
        }
    }

public:
    Graph(int V) { // Constructor
        this->V = V; // Initialize the number of vertices
        adj.resize(V); // Resize the adjacency list vector to accommodate V vertices
    }

    // Function to add an edge to the graph
    // Time Complexity: O(1) for each edge
    void addEdge(int v, int w) { 
        adj[v].push_back(w); // Add w to v’s list (undirected graph)
    }

    // Depth First Search traversal starting from vertex v
    // Overall Time Complexity: O(|V| + |E|)
    void DFS(int v) { 
        // Create a boolean vector to mark visited vertices
        // Time Complexity: O(|V|)
        vector<bool> visited(V, false);
        
        // Call the recursive DFS utility function
        // Time Complexity: O(|V| + |E|) for a complete traversal
        DFSUtil(v, visited); 
    }
};

// Main function
int main() {
    // Create a graph given in the above diagram
    Graph g(4); // Create a graph with 4 vertices numbered from 0 to 3
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Depth First Traversal starting from vertex 2:\n";
    g.DFS(2); // Perform DFS traversal starting from vertex 2
    cout << endl << "Depth First Traversal starting from vertex 1:\n";
    g.DFS(1); // Perform DFS traversal starting from vertex 1
    return 0; // Exit the program
}
