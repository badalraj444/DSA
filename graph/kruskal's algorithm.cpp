// User function Template for C++
class Solution
{
    vector<int> parent, rank; // DSU structures
public:
    int kruskalsMST(int V, vector<vector<int>> &edges)
    {
        // Initialize parent and rank
        parent.resize(V);
        rank.resize(V);
        for (int i = 0; i < V; i++)
        {
            parent[i] = i; // each node is its own parent initially
            rank[i] = 0;   // rank (tree height) = 0
        }

        // Sort edges based on weight (3rd element in edge)
        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] < b[2]; });

        int cost = 0;  // Total weight of MST
        int count = 0; // Number of edges included in MST

        // Process edges in increasing weight order
        for (auto &e : edges)
        {
            int u = e[0], v = e[1], w = e[2];

            // If u and v are already connected, skip (avoid cycle)
            if (find(u) == find(v))
                continue;

            // Otherwise, include this edge
            unite(u, v);
            cost += w;

            // Stop if we already have V-1 edges
            if (++count == V - 1)
                break;
        }
        return cost;
    }

    // Find operation with path compression
    int find(int x)
    {
        return (x == parent[x]) ? x : (parent[x] = find(parent[x]));
    }

    // Union operation with union by rank
    void unite(int x, int y)
    {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY)
            return; // already connected

        int rankX = rank[rootX], rankY = rank[rootY];

        if (rankX < rankY)
        {
            parent[rootX] = rootY; // attach smaller tree under larger
        }
        else if (rankY < rankX)
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootY] = rootX; // both same rank → choose one as root
            rank[rootX]++;         // increase rank of new root
        }
    }
};
