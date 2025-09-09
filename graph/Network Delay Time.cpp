class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build adjacency list
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &t : times){
            int u = t[0], v = t[1], cost = t[2];
            adj[u].push_back({v, cost});
        }

        // Step 2: Distance array
        vector<int> dist(n+1, INT_MAX);

        using node = array<int,2>; // {distance, nodeId}
        priority_queue<node, vector<node>, greater<>> pq;

        // Step 3: Start from source
        pq.push({0, k});
        dist[k] = 0;

        // Step 4: Dijkstra
        while(!pq.empty()){
            auto [cost, u] = pq.top();
            pq.pop();

            // ✅ Trick: if this is not the best distance anymore, skip
            if(cost > dist[u]) continue;

            for(auto [v, c] : adj[u]){
                if(dist[v] > dist[u] + c){
                    dist[v] = dist[u] + c;
                    pq.push({dist[v], v});
                }
            }
        }

        // Step 5: Find answer
        auto it = max_element(dist.begin()+1, dist.end());
        return (*it == INT_MAX) ? -1 : *it;
    }
};

/*
-----------------------------------
💡 IDEA:
- Use Dijkstra’s algorithm to compute shortest paths from k.
- Answer = maximum shortest path distance.
- If some node is unreachable, return -1.

-----------------------------------
🔑 INTUITION:
- No need for visited[].
- Trick: When popping from pq, if the distance is already outdated 
  (i.e., cost > dist[u]), skip it.
- Why? Because in Dijkstra, once a node comes out with the smallest distance,
  any later (larger) distances for the same node are useless.

- This keeps code cl
