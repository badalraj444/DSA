#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // ----------------------------
        // 1. Build adjacency list + cost matrix
        // ----------------------------
        vector<vector<int>> adj(V);
        vector<vector<int>> cost(V, vector<int>(V, 0));
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back(v);
            cost[u][v] = w;
        }

        // ----------------------------
        // 2. Topological Sort
        // ----------------------------
        vector<bool> visited(V, false);
        stack<int> st; // stores nodes in reverse topological order
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, st);
            }
        }

        // Extract nodes from stack into topological order list
        vector<int> tpOrder;
        while (!st.empty()) {
            tpOrder.push_back(st.top());
            st.pop();
        }

        // ----------------------------
        // 3. Shortest Path Relaxation
        // ----------------------------
        vector<int> dist(V, INT_MAX);
        dist[0] = 0; // assuming source = 0

        for (int u : tpOrder) {
            // Only process if node is reachable
            if (dist[u] != INT_MAX) {
                for (int v : adj[u]) {
                    dist[v] = min(dist[v], dist[u] + cost[u][v]);
                }
            }
        }

        // ----------------------------
        // 4. Mark unreachable nodes as -1
        // ----------------------------
        for (auto &d : dist) {
            if (d == INT_MAX) d = -1;
        }

        return dist;
    }

private:
    // DFS helper for topological sort
    void dfs(int u, vector<bool> &visited, vector<vector<int>> &adj, stack<int> &st) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, visited, adj, st);
            }
        }
        st.push(u); // push after exploring descendants
    }
};
