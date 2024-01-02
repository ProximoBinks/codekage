#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph{
    int numVertices; // Number of vertices in the graph
    vector<list<int>> adjLists; // Adjacency lists for each vertex
    void DFSUtil(int v, vector<bool>& visited); // Utility function for DFS

public:
    // Constructor initializing the graph with a given number of vertices
    Graph(int vertices) : numVertices(vertices), adjLists(vertices) {}

    // Function to add an edge between two vertices
    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
    }

    // Function to perform DFS starting from vertex v
    void DFS(int v);
};

// Utility function for performing DFS recursively
void Graph::DFSUtil(int v, vector<bool>& visited) {
    visited[v] = true; // Mark the current node as visited
    cout << v << " "; // Print the current node

    // Recur for all the vertices adjacent to this vertex
    for (int adj : adjLists[v]) {
        if (!visited[adj]) {
            DFSUtil(adj, visited); // Recursive call if not visited
        }
    }
}

// DFS traversal of the vertices reachable from v
void Graph::DFS(int v) {
    vector<bool> visited(numVertices, false); // Initialize all vertices as not visited
    DFSUtil(v, visited); // Call the recursive helper function to print DFS traversal
}

int main() {
    Graph g(5); // Create a graph with 5 vertices
    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "Depth First Traversal (starting from vertex 0) : \n";
    g.DFS(0); // Perform DFS starting from vertex 0

    return 0; // End of the program
}