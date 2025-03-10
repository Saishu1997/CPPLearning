#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

#define INF numeric_limits<int>::max()

void Dijkstra(vector<vector<pair<int, int>>>& graph, int src)
{
    int V = graph.size();
    vector<int> dist(V, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, weight] : graph[u])
        {
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++)
    {
        cout << "To" << i << ": " << (dist[i] == INF ? -1 : dist[i]) << "\n";
    }
}

int main()
{
    int V = 5;
    vector<vector<pair<int, int>>> graph(V);

    graph[0] = {{1, 2}, {4, 6}};
    graph[1] = {{0, 2}, {2, 3}, (3, 1), (4, 2)};
    graph[2] = {{1, 3}, {3, 1}};
    graph[3] = {{1, 1}, {2, 1}, {4, 5}};
    graph[4] = {{0, 6}, {1, 2}, {3, 5}};

    Dijkstra(graph, 0);

    return 0;
}
