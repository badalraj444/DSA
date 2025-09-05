// BFS
class Solution
{
public:
    // Function to detect cycle in an undirected graph using BFS
    bool isCycle(int V, vector<int> adj[])
    {
        // Visited array to track visited nodes
        vector<int> vis(V, 0);

        // Loop through all vertices (to handle disconnected components)
        for (int i = 0; i < V; i++)
        {
            // If already visited, skip
            if (vis[i])
                continue;

            // Queue to perform BFS: stores {current_node, parent_node}
            queue<pair<int, int>> q;
            q.push({i, -1}); // Start BFS from node i, with no parent
            vis[i] = 1;      // Mark the starting node as visited

            while (!q.empty())
            {
                auto [x, parent] = q.front(); // Current node and its parent
                q.pop();

                // Traverse all adjacent nodes
                for (int y : adj[x])
                {
                    if (vis[y] == 1 && y != parent)
                    {
                        // If adjacent node is visited and not the parent,
                        // then a cycle is found
                        return true;
                    }
                    if (vis[y] == 0)
                    {
                        // If not visited, add to queue and mark visited
                        q.push({y, x});
                        vis[y] = 1;
                    }
                }
            }
        }

        // If no cycle detected in any component
        return false;
    }
};
// DFS

// class Solution {
// public:
//     // Function to detect cycle in an undirected graph using DFS
//     bool isCycle(int V, vector<int> adj[]) {
//         vector<int> vis(V, 0);  // Visited array to keep track of visited nodes

//         // Loop through all vertices (handles disconnected components)
//         for (int i = 0; i < V; i++) {
//             if (vis[i] == 0) {
//                 // If not visited, start DFS from this node
//                 if (dfs(i, -1, adj, vis))
//                     return true;  // If cycle is found, return true
//             }
//         }

//         // No cycle found in any component
//         return false;
//     }

//     // Helper DFS function to detect a cycle
//     bool dfs(int node, int parent, vector<int> adj[], vector<int>& vis) {
//         vis[node] = 1;  // Mark the current node as visited

//         // Visit all adjacent nodes
//         for (int neighbor : adj[node]) {
//             if (vis[neighbor] == 0) {
//                 // If neighbor is unvisited, recursively DFS
//                 if (dfs(neighbor, node, adj, vis))
//                     return true;
//             }
//             // If neighbor is visited and not parent, cycle exists
//             else if (neighbor != parent) {
//                 return true;
//             }
//         }

//         // No cycle detected from this path
//         return false;
//     }
// };
