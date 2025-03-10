#include <iostream>
#include <vector>
using namespace std;

void DFSUtil(int node, vector<vector<int>>& adjList, vector<bool>& visited)
{
    visited[node] = true;
    cout << node << " ";
    for(int neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            DFSUtil(neighbor, adjList, visited);
        }
    }
}

void DFS(vector<vector<int>>& adjList, int start)
{
    vector<bool> visited(adjList.size(), false);
    DFSUtil(start, adjList, visited);
}

int main()
{
    vector<vector<int>> graph = {
        {1, 4}, {0, 2, 3, 4}, {1, 3}, {1, 2, 4}, {0, 1, 3}
    };

    cout << "DFS Traversal: ";
    DFS(graph, 0);

    return 0;
}