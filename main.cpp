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
    Graph(int V) {
        this->V = V; // Initialize the number of vertices
        adj.resize(V); // Resize the adjacency list vector to accommodate V vertices
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v’s list.
        adj[w].push_back(v); // Since the graph is undirected, add v to w's list as well.
    }

    // Print the adjacency list representation of the graph
    void printGraph() {
        for (int v = 0; v < V; ++v) { // Iterate through all vertices
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
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Print the adjacency list representation of the graph
    g.printGraph();

    return 0; // Exit the program
}
