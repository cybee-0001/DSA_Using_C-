#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int v, vector<int> adj[]){
    int vis[v]={0};
    vis[0]=1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;

    while(q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }

    return bfs;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < m; i++) {  // Loop should run m times for m edges
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // Since it's an undirected graph
    }

    // Print the adjacency list
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " makes an edge with:\n";
        for (auto edge : adj[i]) {
            cout << "  Node " << edge.first << " with weight " << edge.second << endl;
        }
        cout << endl;
    }

    return 0;
}
