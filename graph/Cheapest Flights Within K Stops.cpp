class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build adjacency list: adj[u] = { (v, cost) }
        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            int u = f[0], v = f[1], c = f[2];
            adj[u].push_back({v, c});
        }

        // stops[u] = minimum number of stops used so far to reach node u
        vector<int> stops(n, INT_MAX);

        using node = array<int,3>; // {cost, node, stops_used}
        // Min-heap ordered by cost (since array<int,3> with greater<> sorts lexicographically)
        priority_queue<node, vector<node>, greater<node>> pq;

        // Start from src with cost = 0 and stops_used = 0
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, u, k1] = pq.top(); pq.pop();

            // If we reached destination, return the cost
            // Since pq is cost-ordered, this is guaranteed to be the cheapest
            if (u == dst) return cost;

            // If we exceeded allowed stops, discard this path
            // If we already reached u with fewer stops, skip this path as well
            if (k1 > k || k1 > stops[u]) continue;

            // Record the minimum stops used to reach u
            stops[u] = k1;

            // Explore neighbors
            for (auto [v, price] : adj[u]) {
                // Push new state with updated cost and stops_used+1
                pq.push({cost + price, v, k1 + 1});
            }
        }

        // Destination not reachable within k stops
        return -1;
    }
};


/*
KEY OBSERVATIONS & INSIGHTS:
. This problem looks like Dijkstra (shortest path) but with an extra constraint: 
  we can only take at most k stops.
. Normal Dijkstra guarantees the shortest cost path to each node, but it does NOT 
  track how many stops were used. It could find the cheapest path with 100 stops, 
  10 stops, or 3 stops — but here we must restrict to ≤ k stops.
. Hence, we explicitly carry "stops_used" in the state and check:
    - If stops_used > k → discard this path.
    - If stops_used > stops[u] (minimum stops recorded so far for node u) → skip, 
      because we already reached u with fewer stops. Since that happened earlier 
      in the PQ (which is cost-ordered), it must also be cheaper, so no need to relax again.
. This avoids infinite re-expansion without losing correctness.

WHY NOT JUST VISITED/DIST?
. We cannot mark nodes as simply visited, because the first arrival might use 
  too many stops. We might later reach the same node with fewer stops (and possibly 
  better cost). So we must allow multiple visits but prune intelligently.
. We also don’t do the standard Dijkstra "relaxation" step with dist[u] updates 
  alone, since here the stop constraint is equally important.

ALGORITHM:
1. Build adjacency list from flights.
2. Use a modified Dijkstra with a min-heap (priority queue):
   - Each state = {cost, node, stops_used}.
   - Initialize pq with {0, src, 0}.
3. While pq is not empty:
   - Pop the state with the smallest cost.
   - If node == dst, return cost (PQ guarantees this is minimum).
   - If stops_used > k, skip.
   - If stops_used > stops[node], skip (better path already processed).
   - Otherwise, record stops[node] = stops_used.
   - Push neighbors with updated cost and stops_used+1.
4. If destination not reached within k stops, return -1.

NOTES:
. PQ ensures paths are explored in increasing order of cost.
. Stops array ensures we don’t waste time on worse stop-count paths.
. This is essentially "Dijkstra with a bounded depth".
*/
