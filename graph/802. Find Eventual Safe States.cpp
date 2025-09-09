class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<vector<int>> rgraph(n);  // reversed graph
        vector<int> indegree(n);        // indegree count for reversed graph

        // Step 1: Reverse the graph
        // Original: i -> j
        // Reverse : j -> i
        for (int i = 0; i < n; i++) {
            for (int j : graph[i]) {
                rgraph[j].push_back(i);  // reverse edge
                indegree[i]++;           // increase indegree of parent
            }
        }

        // Step 2: Initialize queue with nodes that have indegree = 0
        // These are terminal nodes (no outgoing edges in original graph)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }

        // Step 3: Kahn's algorithm (BFS on reversed graph)
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // For every parent of u in reversed graph
            for (int v : rgraph[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                    ans.push_back(v);
                }
            }
        }

        // Step 4: Sort result before returning
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*
KEY OBSERVATIONS & INSIGHTS:
- A node is "safe" if every path starting from it ends in a terminal node.
- If a node eventually leads into a cycle, it is NOT safe.
- Instead of directly detecting cycles, we can reverse the graph and perform
  a topological sort (Kahn’s algorithm).
- All nodes that can reach terminal nodes (in reversed graph) are safe.

ALGORITHM:
1. Reverse the graph: for every edge i -> j, add j -> i in reversed graph.
2. Count indegree for each node (in reversed graph).
3. Start with all nodes that have indegree = 0 (terminal nodes in original graph).
4. Perform BFS (Kahn’s algorithm):
   - Remove node from queue
   - Decrease indegree of its parents
   - If parent’s indegree becomes 0, it is safe → push to queue
5. At the end, all collected nodes are safe.
6. Sort the result and return.

TIME COMPLEXITY:
- O(V + E) for building reverse graph and BFS
- O(V log V) for sorting
- Total: O(V + E + V log V)

SPACE COMPLEXITY:
- O(V + E) for storing reversed graph and indegree
*/
