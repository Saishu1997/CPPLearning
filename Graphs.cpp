/*

A Graph is a collection of nodes (vertices) connected by edges. They can be:

Directed (one-way edges)
Undirected (two-way edges)
Weighted (edges have weights)
Unweighted (edges have no weight)

*/

#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<int>> adjList;

public:
    Graph(int v)
    {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void display()
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << "Vertex " << i << ": ";
            for (int neighbour : adjList[i])
            {
                cout << neighbour << " ";
            }
            cout << endl;
        }
        
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.display();

    return 0;
}