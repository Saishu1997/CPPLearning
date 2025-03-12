/*

Depth-First Search (DFS) is a graph traversal algorithm that explores as far as possible along one branch before backtracking. 
It uses a stack (either explicitly or through recursion) to track nodes.

DFS is useful for:

Pathfinding in mazes
Cycle detection in graphs
Topological sorting
Connected components detection
Unlike BFS, DFS does not guarantee the shortest path but is efficient for exploring deep structures like trees and backtracking problems.

*/

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
