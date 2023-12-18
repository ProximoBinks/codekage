#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph{
    int numVertices;
    vector<list<int>> adjLists;
    void DFSUtil(int v, vector<bool>& visited);

public:
    Graph(int vertices) : numVertices(vertices), adjLists(vertices) {}

    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
    }

    void DFS(int v);
};

void Graph::DFSUtil(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int adj : adjLists[v]) {
        if (!visited[adj]) {
            DFSUtil(adj, visited);
        }
    }
}

void Graph::DFS(int v) {
    vector<bool> visited(numVertices, false);
    DFSUtil(v, visited);
}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "Depth First Traversal (starting from vertex 0) : \n";
    g.DFS(0);

    return 0;
}