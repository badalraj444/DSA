#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<int> ans;
        vector<int> inc(V);
        vector<vector<int>> adj(V);
        queue<int> q;
        // incoming matrix and adj matrix
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            inc[y]++;
            adj[x].push_back(y);
        }
        // push all nodes with 0 inc to q
        for (int i = 0; i < V; i++)
        {
            if (inc[i] == 0)
                q.push(i);
        }
        // process queue
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (int v : adj[u])
            {
                inc[v]--;
                if (inc[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        return ans;
    }
};