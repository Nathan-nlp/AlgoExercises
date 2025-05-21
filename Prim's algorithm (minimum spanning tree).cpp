#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

int main() { 
    int n = 5;
    vector<vector<Edge>> graph(n);
    //Constructing an undirected graph
    graph[0].push_back({1, 2});
    graph[1].push_back({0, 2});
    graph[0].push_back({3, 6});
    graph[3].push_back({0, 6});
    graph[1].push_back({2, 3});
    graph[2].push_back({1, 3});
    graph[1].push_back({3, 8});
    graph[3].push_back({1, 8});
    graph[1].push_back({4, 5});
    graph[4].push_back({1, 5});
    graph[2].push_back({4, 7});
    graph[4].push_back({2, 7});

    vector<bool> visited(n, false);
    // Priority queue, storing (weight, vertex)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    int mst_weight = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        mst_weight += weight;

        for (auto &edge : graph[u]) {
            if (!visited[edge.to]) {
                pq.push({edge.weight, edge.to});
            }
        }
    }

    cout << "The minimum spanning tree weight sum calculated by Prim's algorithm is:" << mst_weight << endl;
    return 0;
}

