#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<list<int>> adj; // Adjacency lists

    // Utility function for Depth First Search (DFS)
    // Overall Time Complexity for complete traversal: O(|V| + |E|)
    void DFSUtil(int v, vector<bool> &visited) {
        // Mark the current node as visited and print it
        // Time Complexity: O(1)
        visited[v] = true;
        cout << v << " ";

        // Recur for all the vertices adjacent to this vertex
        // Time Complexity for all vertices and their adjacent vertices: O(|V| + |E|)
        for (int adjVertex : adj[v]) {
            if (!visited[adjVertex]) {
                DFSUtil(adjVertex, visited); // Recursively call DFS on the unvisited adjacent vertices
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
        adj[v].push_back(w); // Add w to v’s list (directed graph)
    }

    // Depth First Search traversal starting from vertex v
    // Overall Time Complexity: O(|V| + |E|)
    void DFS(int v) { 
        // Create a boolean vector to mark visited vertices
        // Time Complexity: O(|V|)
        vector<bool> visited(V, false);
        
        // Call the recursive helper function to print DFS traversal
        // Time Complexity: O(|V| + |E|) for a complete traversal
        DFSUtil(v, visited); 
    }
};

// Main function
int main() {
    // Create a graph given in the diagram
    Graph g(4); // Create a graph with 4 vertices numbered from 0 to 3
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Depth First Traversal starting from vertex 2:\n";
    g.DFS(2); // Perform DFS traversal starting from vertex 2
    cout << endl;
    
    return 0; // Exit the program
}