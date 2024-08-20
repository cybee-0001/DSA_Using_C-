#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    // Initialize the adjacency matrix to 0
    int adj[n + 1][n + 1] = {0};

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u;
        cin >> v;

        // Set the adjacency matrix to 1 for undirected graph
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    return 0;
}
