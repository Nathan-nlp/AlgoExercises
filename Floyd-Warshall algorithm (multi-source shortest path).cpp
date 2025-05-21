#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    int n = 4;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    dist[0][1] = 5;
    dist[0][3] = 10;
    dist[1][2] = 3;
    dist[2][3] = 1;

    // Floyd-Warshall main loop
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    // Output distance matrix
    cout << "The shortest distance between any two points:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

