#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<int> ans;
        vector<bool> visited(V, false);
        stack<int> st;
        // adjacency matrix of graph
        vector<vector<int>> adj(V);
        for (auto &e : edges)
        {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }
        // dfs
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs(i, visited, adj, st);
        }
        // get ans from stack
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        // return
        return ans;
    }

private:
    void dfs(int i, vector<bool> &visited, vector<vector<int>> &adj, stack<int> &st)
    {
        visited[i] = true;
        // visit any unvisited node
        for (int j : adj[i])
        {
            if (!visited[j])
                dfs(j, visited, adj, st);
        }
        // push it to stack, it means it will come out before its dependents
        st.push(i);
    }
};