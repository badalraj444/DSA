
#include <vector>
#include <queue>
using namespace std;

bool hasCycleKahn(int V, const vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    vector<int> indeg(V, 0);
    for (auto &e : edges) {
        int u = e[0], v = e[1];   // u -> v
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < V; ++i)
        if (indeg[i] == 0) q.push(i);

    int processed = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        processed++;
        for (int v : adj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    return processed < V; // true => cycle exists
}

