#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
private:
    int V; // No. of vertices
    vector<list<int>> adj; // Adjacency lists

public:
    // Constructor
    // Time Complexity: O(V), as it initialises a vector of lists for V vertices.
    Graph(int V) {
        this->V = V; // Initialise the number of vertices
        adj.resize(V); // Resize the adjacency list vector to accommodate V vertices
    }

    // Function to add an edge to the graph
    // Time Complexity: O(1), assuming push_back operation is O(1) on average.
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v’s list.
        adj[w].push_back(v); // Since the graph is undirected, add v to w's list as well.
    }

    // Print the adjacency list representation of the graph
    // Overall Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
    void printGraph() {
        for (int v = 0; v < V; ++v) { // Iterate through all vertices
            // Time Complexity for each vertex: O(deg(v)), where deg(v) is the degree of vertex v (i.e., number of edges).
            cout << "\n Adjacency list of vertex " << v << "\n head ";
            for (auto x : adj[v]) // Iterate through the adjacency list of the current vertex
                cout << "-> " << x; // Print each adjacent vertex
            printf("\n"); // Move to the next line for the next vertex
        }
    }
};

// Main function
int main() {
    // Create a graph given in the above diagram
    Graph g(5); // Create a graph with 5 vertices numbered from 0 to 4
    // Adding edges is a constant time operation for each edge.
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Print the adjacency list representation of the graph
    // Overall Time Complexity: O(V + E)
    g.printGraph();

    return 0; // Exit the program
}