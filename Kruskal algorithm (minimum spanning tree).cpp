#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge &e) const {
        return weight < e.weight;
    }
}; 

// And search the collection
struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n): parent(n), rank(n, 0) {
        for(int i=0; i<n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) parent[rx] = ry;
        else {
            parent[ry] = rx;
            if (rank[rx] == rank[ry]) rank[rx]++;
        }
        return true;
    }
};

int main() {
    int n = 5;
    vector<Edge> edges = {
        {0,1,10}, {0,2,6}, {0,3,5},
        {1,3,15}, {2,3,4}
    };

    sort(edges.begin(), edges.end());

    UnionFind uf(n);
    int mst_weight = 0;
    vector<Edge> mst;

    for (auto &e : edges) {
        if (uf.unite(e.u, e.v)) {
            mst.push_back(e);
            mst_weight += e.weight;
        }
    }

    cout << "The sum of the edges and weights of the minimum spanning tree is:" << mst_weight << endl;
    cout << "Included edges:" << endl;
    for (auto &e : mst) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }

    return 0;
}

