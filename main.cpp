#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<list<int>> adj; // Adjacency lists

public:
    Graph(int V) { // Constructor
        this->V = V; // Initialise the number of vertices
        adj.resize(V); // Resize the adjacency list vector to accommodate V vertices
    }

    void addEdge(int v, int w) { // Function to add an edge to the graph
        adj[v].push_back(w); // Add w to v’s list (undirected graph)
    }

    void BFS(int s) { // Breadth First Search traversal starting from a given source s
        // Mark all the vertices as not visited
        vector<bool> visited(V, false);
        
        // Create a queue for BFS
        queue<int> queue;

        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.push(s);

        while(!queue.empty()) {
            // Dequeue a vertex from the queue and print it
            s = queue.front();
            cout << s << " ";
            queue.pop();

            // Get all adjacent vertices of the dequeued vertex s
            // If an adjacent vertex has not been visited, then mark it visited and enqueue it
            for (int adjVertex : adj[s]) {
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    queue.push(adjVertex);
                }
            }
        }
    }
};

// Main function
int main() {
    Graph g(4); // Create a graph with 4 vertices numbered from 0 to 3
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Breadth First Traversal starting from vertex 3:\n";
    g.BFS(3); // Perform BFS traversal starting from vertex 2
    cout << endl;
    cout << "Breadth First Traversal starting from vertex 2:\n";
    g.BFS(2); // Perform BFS traversal starting from vertex 2
    cout << endl;
    cout << "Breadth First Traversal starting from vertex 1:\n";
    g.BFS(1); // Perform BFS traversal starting from vertex 1
    return 0; // Exit the program
}