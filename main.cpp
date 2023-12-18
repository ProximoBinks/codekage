#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph {
    int numVertices;
    vector<list<int>> adjLists;

public:
    Graph(int vertices) :numVertices(vertices), adjLists(vertices) {}
    
    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
    }

    void BFS(int s) {
        vector<bool> visited(numVertices, false);
        queue<int> queue;

        visited[s] = true;
        queue.push(s);

        while (!queue.empty()) {
            s = queue.front();
            cout << s << " ";
            queue.pop();

            for (auto adj :adjLists[s]) {
                if (!visited[adj]) {
                    visited[adj] = true;
                    queue.push(adj);
                }
            }
        }
    }
};

int main() { 
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "Breath First Traversal (starting from vertex 0): \n";
    g.BFS(0);

    return 0;
}