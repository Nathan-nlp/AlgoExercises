#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

vector<int> dijkstra(int start, const vector<vector<Edge>> &graph) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    //Priority queue stores (distance, vertex)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [curDist, u] = pq.top();
        pq.pop();

        if (curDist > dist[u]) continue;

        for (auto &edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n = 5; // Number of vertices
    vector<vector<Edge>> graph(n);
    // Constructing a graph (undirected graph example)
    graph[0].push_back({1, 2});
    graph[1].push_back({0, 2});
    graph[0].push_back({2, 4});
    graph[2].push_back({0, 4});
    graph[1].push_back({2, 1});
    graph[2].push_back({1, 1});
    graph[1].push_back({3, 7});
    graph[3].push_back({1, 7});
    graph[2].push_back({4, 3});
    graph[4].push_back({2, 3});
    graph[3].push_back({4, 1});
    graph[4].push_back({3, 1});

    int start = 0;
    vector<int> dist = dijkstra(start, graph);

    cout << "The shortest distance from vertex" << start << "to other vertices:" << endl;
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) cout << i << ": Unable to reach" << endl;
        else cout << i << ": " << dist[i] << endl;
    }

    return 0;
}

