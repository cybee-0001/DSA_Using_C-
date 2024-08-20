#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u;
        cin >> v;

        adj[u].push_back(v);
        
    }

    return 0;
}
