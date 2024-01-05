#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<list<int>> adj; // Adjacency lists

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

    // Iterative Depth First Search traversal starting from vertex v
    // Overall Time Complexity: O(|V| + |E|)
    void DFS(int v) { 
        // Create a boolean vector to mark visited vertices
        // Time Complexity: O(|V|)
        vector<bool> visited(V, false);
        
        // Stack for DFS
        // Using a stack ensures that we explore the last discovered node first,
        // which is the essence of Depth First Search
        stack<int> stack;

        // Push the starting vertex
        stack.push(v);

        while (!stack.empty()) {
            // Pop a vertex from stack and print it
            v = stack.top();
            stack.pop();

            // Stack may contain the same vertex twice. So
            // we need to print the popped item only if it is not visited.
            if (!visited[v]) {
                cout << v << " ";
                visited[v] = true; // Mark the vertex as visited
            }

            // Get all adjacent vertices of the popped vertex v
            // If an adjacent has not been visited, then push it to the stack.
            // Time Complexity for all vertices and their adjacent vertices: O(|V| + |E|)
            for (int adjVertex : adj[v]) {
                if (!visited[adjVertex]) {
                    stack.push(adjVertex);
                }
            }
        }
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

    cout << "Iterative Depth First Traversal starting from vertex 2:\n";
    g.DFS(2); // Perform DFS traversal starting from vertex 2
    cout << endl << "Iterative Depth First Traversal starting from vertex 1:\n";
    g.DFS(1); // Perform DFS traversal starting from vertex 1
    return 0; // Exit the program
}