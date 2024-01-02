#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph {
    int numVertices; // Number of vertices in the graph
    vector<list<int>> adjLists; // Adjacency lists for each vertex

public:
    // Constructor initializing the graph with a given number of vertices
    Graph(int vertices) :numVertices(vertices), adjLists(vertices) {}
    
    // Function to add an edge between two vertices
    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
    }

    // Function to delete an edge between two vertices
    void deleteEdge(int src, int dest) {
        adjLists[src].remove(dest); // Remove dest from src's adjacency list
        adjLists[dest].remove(src); // Remove src from dest's adjacency list
    }

    // Function to perform BFS starting from vertex s
    void BFS(int s) {
        vector<bool> visited(numVertices, false); // Keep track of visited vertices
        queue<int> queue; // Queue to manage the order of visiting vertices

        visited[s] = true; // Mark the starting vertex as visited
        queue.push(s); // Enqueue the starting vertex

        // Continue until the queue is empty
        while (!queue.empty()) {
            s = queue.front(); // Get the front vertex in the queue
            cout << s << " "; // Print the current vertex
            queue.pop(); // Dequeue

            // Go through the adjacency list of the current vertex
            for (auto adj : adjLists[s]) {
                // If an adjacent vertex hasn't been visited
                if (!visited[adj]) {
                    visited[adj] = true; // Mark it as visited
                    queue.push(adj); // Enqueue it
                }
            }
        }
    }
};

int main() { 
    Graph g(5); // Create a graph with 5 vertices
    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "Breath First Traversal (starting from vertex 0): \n";
    g.BFS(0);

    cout << "\nDeleting edge (1, 4)\n";
    g.deleteEdge(1, 4); // Delete edge between vertex 1 and 4

    cout << "Breath First Traversal after deleting edge (starting from vertex 0): \n";
    g.BFS(0);

    return 0; // End of the program
}
