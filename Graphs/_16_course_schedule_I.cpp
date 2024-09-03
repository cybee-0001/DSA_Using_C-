#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        // Topological Sort
        vector<int> indegree(V, 0); // Initialize the vector with 0

        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo.size() == V;
    }
};

int main() {
    int V, m;
    cout << "Enter the number of courses (vertices): ";
    cin >> V;

    cout << "Enter the number of prerequisites (edges): ";
    cin >> m;

    vector<vector<int>> prerequisites(m, vector<int>(2));
    cout << "Enter the prerequisites pairs (u, v) where course u depends on v:\n";
    for (int i = 0; i < m; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    Solution obj;
    bool result = obj.canFinish(V, prerequisites);

    if (result) {
        cout << "All courses can be finished." << endl;
    } else {
        cout << "Not all courses can be finished due to a cycle." << endl;
    }

    return 0;
}
