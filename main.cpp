#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<list<int>> adj; // Adjacency lists

    // Utility function for Depth First Search (DFS)
    void DFSUtil(int v, vector<bool> &visited) {
        // Mark the current node as visited and print it
        visited[v] = true;
        cout << v << " ";

        // Recur for all the vertices adjacent to this vertex
        for (int adjVertex : adj[v]) {
            if (!visited[adjVertex]) {
                DFSUtil(adjVertex, visited); // Recursively call DFS on adjacent vertices
            }
        }
    }

public:
    Graph(int V) { // Constructor
        this->V = V; // Initialize the number of vertices
        adj.resize(V); // Resize the adjacency list vector to accommodate V vertices
    }

    void addEdge(int v, int w) { // Function to add an edge to the graph
        adj[v].push_back(w); // Add w to v’s list (undirected graph)
    }

    void DFS(int v) { // Depth First Search traversal starting from vertex v
        vector<bool> visited(V, false); // Create a boolean vector to mark visited vertices
        DFSUtil(v, visited); // Call the recursive DFS utility function
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

    return 0; // Exit the program
}