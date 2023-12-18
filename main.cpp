#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int numVertices;
    vector<list<int>> adjLists;

public:
    Graph(int vertices) : numVertices(vertices), adjLists(vertices) {}

    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Adjacency list of vertex " << i << ": ";
            for (auto v : adjLists[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}