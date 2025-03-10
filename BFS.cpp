// Breadth-First Search (BFS) → Uses a queue (FIFO)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& adjList, int start)
{
    vector<bool> visited(adjList.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    vector<vector<int>> graph = {
        {1, 4}, {0, 2, 3, 4}, {1, 3}, {1, 2, 4}, {0, 1, 3}
    };

    cout << "BFS Traversal: ";
    BFS(graph, 0);
    
    return 0;
}