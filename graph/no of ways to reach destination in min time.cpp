class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;

        // Build adjacency list (bidirectional graph)
        vector<vector<pair<int,int>>> adj(n);
        for (auto &r : roads) {
            int u = r[0], v = r[1], c = r[2];
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }

        // Distance array (64-bit to prevent overflow)
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        // Ways[i] = number of shortest paths to reach node i
        vector<int> ways(n, 0);
        ways[0] = 1;

        using node = pair<long long,int>; // (distance, node)
        priority_queue<node, vector<node>, greater<>> pq;
        pq.push({0, 0}); // start with source node 0 at dist = 0

        // Dijkstra’s algorithm
        while (!pq.empty()) {
            auto [cost, u] = pq.top(); pq.pop();
            if (cost > dist[u]) continue; // skip outdated entry

            for (auto [v, c] : adj[u]) {
                long long newDist = dist[u] + c;

                // Case 1: Found a strictly shorter path → reset dist & ways
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u]; // inherit count from parent
                    pq.push({dist[v], v});
                } 
                // Case 2: Found another path with equal shortest distance
                else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
                // Case 3: Longer path → ignore
            }
        }

        return ways[n-1]; // result: number of shortest paths to destination
    }
};
// 📌 KEY-OBSERVATIONS & INSIGHTS (Revised for Revision)

// Core problem = Dijkstra’s shortest path, but we also count how many shortest paths exist.

// Distance update logic:

// If a shorter path is found → reset ways[v] = ways[u].

// If an equal shortest path is found → add ways[u] to ways[v].

// If longer → ignore.

// Correctness:

// ways[u] always holds the count of shortest paths to u.

// When extending to neighbor v, we propagate these counts depending on whether the new path is strictly better or equal.

// Modulo is applied only when adding counts, to keep numbers bounded.

// Implementation details:

// Use LLONG_MAX for distances (since edge weights sum can exceed INT_MAX).

// Priority queue stores (distance, node) to always expand the smallest distance first.

// Graph must be bidirectional, so push both (u,v) and (v,u).