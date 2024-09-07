#include <bits/stdc++.h>
using namespace std;

class Graph{

public:
    unordered_map<int, list<int>> adj;

    // direction = 0 for undirected, 1 for directed
    void addEdges(int u, int v, bool direction){
        adj[u].push_back(v);
        if(direction == 0){  // undirected graph
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto it: adj){
            cout << it.first << " -> ";
            for(auto it2: it.second){
                cout << it2 << ", ";
            }
            cout << endl;
        }
    }
};

int main(){

    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    Graph g;

    for(int i = 0; i < m; i++){
        int u, v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;

        // Creating an undirected graph (direction = 0)
        g.addEdges(u, v, 0);
    }

    // printing Graph
    g.printAdjList();

    return 0;
}
