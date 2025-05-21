#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

struct Vertex {
    int val;
    Vertex(int v) : val(v) {}
};

struct GraphAdjList {
    unordered_map<Vertex*, vector<Vertex*>> adjList;
};

//BFS
vector<Vertex*> graphBFS(GraphAdjList &graph, Vertex *startVet) {
    vector<Vertex*> res;
    unordered_set<Vertex*> visited = {startVet};
    queue<Vertex*> que;
    que.push(startVet);

    while (!que.empty()) {
        Vertex *vet = que.front();
        que.pop();
        res.push_back(vet);

        for (auto adjVet : graph.adjList[vet]) {
            if (visited.count(adjVet)) continue;
            que.push(adjVet);
            visited.emplace(adjVet);
        }
    }
    return res;
}

void dfs(GraphAdjList &graph, unordered_set<Vertex*> &visited, vector<Vertex*> &res, Vertex *vet) {
    res.push_back(vet);
    visited.emplace(vet);
    for (Vertex *adjVet : graph.adjList[vet]) {
        if (visited.count(adjVet)) continue;
        dfs(graph, visited, res, adjVet);
    }
}

//DFS
vector<Vertex*> graphDFS(GraphAdjList &graph, Vertex *startVet) {
    vector<Vertex*> res;
    unordered_set<Vertex*> visited;
    dfs(graph, visited, res, startVet);
    return res;
}

void printTraversal(const vector<Vertex*> &res) {
    for (auto v : res) {
        cout << v->val << " ";
    }
    cout << endl;
}

int main() {
    Vertex v1(1), v2(2), v3(3), v4(4), v5(5);

    GraphAdjList graph;
    graph.adjList[&v1] = {&v2, &v3};
    graph.adjList[&v2] = {&v4};
    graph.adjList[&v3] = {&v4, &v5};
    graph.adjList[&v4] = {&v5};
    graph.adjList[&v5] = {};

    cout << "BFS traversal sequence:";
    auto bfsRes = graphBFS(graph, &v1);
    printTraversal(bfsRes);

    cout << "DFS traversal sequence:";
    auto dfsRes = graphDFS(graph, &v1);
    printTraversal(dfsRes);

    return 0;
}

