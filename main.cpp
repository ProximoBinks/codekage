#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Graph class defines a graph using an adjacency list
class Graph {
    int numVertices; // Number of vertices in the graph
    vector<list<int>> adjLists; // Vector of lists to represent the adjacency list

public:
    // Constructor initializes a graph with a given number of vertices
    Graph(int vertices) : numVertices(vertices), adjLists(vertices) {}

    // Function to add an edge between two vertices (src and dest)
    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest); // Add dest to the list of src's adjacent vertices
        adjLists[dest].push_back(src); // Add src to the list of dest's adjacent vertices (for an undirected graph)
    }

    // Function to print the adjacency list representation of the graph
    void printGraph() {
        for (int i = 0; i < numVertices; i++) { // Iterate through all vertices
            cout << "Adjacency list of vertex " << i << ": ";
            for (auto v : adjLists[i]) { // Iterate through the list of adjacent vertices
                cout << v << " "; // Print the adjacent vertex
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices
    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph(); // Print the adjacency list representation of the graph

    return 0; // End of the program
}
