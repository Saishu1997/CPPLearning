\*
    The A (A-Star) Algorithm* is a pathfinding and graph traversal algorithm used to find the shortest path between nodes. It combines the advantages of Dijkstra’s Algorithm (guaranteeing the shortest path) and Greedy Best-First Search (using heuristics for efficiency).

A* evaluates paths using the function:
f(n) = g(n) + h(n)
Where:

g(n) = Cost from the start node to the current node
h(n) = Heuristic estimate of the cost from the current node to the goal
By balancing actual cost and estimated cost, A* finds an optimal path efficiently.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>

using namespace std;

#define INF numeric_limits<double>::max()

struct Node
{
    int x, y;
    double g, h, f;
    Node* parent;

    Node(int x, int y, double g, double h, Node* parent = nullptr) : 
        x(x), y(y), g(g), h(h), f(g + h), parent(parent) {}

    bool operator>(const Node& other) const { return f > other.f; }
};

double heuristic(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void AStar(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal)
{
    int rows = grid.size(), cols = grid[0].size();
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    pq.push(Node(start.first, start.second, 0, heuristic(start.first, start.second, goal.first, goal.second)));

    while (!pq.empty())
    {
        Node current = pq.top();
        pq.pop();

        if (current.x == goal.first && current.y == goal.second)
        {
            cout << "Path Found \n";
            return;
        }

        if (visited[current.x][current.y]) continue;
        visited[current.x][current.y] = true;

        vector<pair<int, int>>directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (auto [dx, dy] : directions)
        {
            int nx = current.x + dx, ny = current.y + dy;
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 0 && !visited[nx][ny])
            {
                double g = current.g + 1;
                double h = heuristic(nx, ny, goal.first, goal.second);
                pq.push(Node(nx, ny, g, h, new Node(current)));
            }
        }
    }

    cout << "No path found \n";
}

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };
    AStar(grid, {0, 0}, {4, 4});

    return 0;
}
