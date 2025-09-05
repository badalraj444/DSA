// User Function Template
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // adj matrix
        vector<vector<vector<int>>> adj(V);
        for (auto &e : edges)
        {
            int u = e[0], v = e[1], c = e[2];
            adj[u].push_back({v, c});
        }
        // distances
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        // init min heap
        vector<bool> visited(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        // repeat untill all processed
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (visited[u])
                continue;
            visited[u] = true;
            for (auto &e : adj[u])
            {
                int v = e[0], c = e[1];
                if (dist[u] + c < dist[v])
                {
                    dist[v] = dist[u] + c;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};

/*
KEY-OBSERVATIONS & INSIGHTS:
. non negative weights -> djisktra
. min heap
. initially: src<-0, othters <- infinity
. mark selected when popping not pushing as visited

ALGO:
0 create adj list
1 initialise all nodes distance from src as infinity
2 make src dist 0
3 store dist[0] in min heap using pq pair<dist,v>
4 while pq is not empty
  pop top  <- u
  mark selected
  relax all its unselected nodes v
  push to heap with this

PROBLEMS:

*/