class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &h)
    {
        // Get grid dimensions
        int rows = h.size(), cols = h[0].size();

        // dist[r][c] stores minimum effort to reach (r,c)
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        // vis[r][c] marks whether (r,c) has been processed
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        // Directions: right, left, down, up
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Min-heap: {effort, {row, col}}
        using Node = pair<int, pair<int, int>>;
        priority_queue<Node, vector<Node>, greater<Node>> pq;

        // Start at (0,0) with 0 effort
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        // Standard Dijkstra algorithm
        while (!pq.empty())
        {
            auto [eff, pos] = pq.top(); // Current cell with minimal effort
            pq.pop();
            int r = pos.first, c = pos.second;

            // If we've reached destination, return effort
            if (r == rows - 1 && c == cols - 1)
                return eff;

            // Skip if already visited
            if (vis[r][c])
                continue;
            vis[r][c] = true;

            // Explore 4 neighboring cells
            for (auto &d : dirs)
            {
                int nr = r + d[0]; // Neighbor row
                int nc = c + d[1]; // Neighbor col

                // Check boundaries & visited state
                if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && !vis[nr][nc])
                {
                    // Effort to reach neighbor is max of current path effort
                    // and height difference between current and neighbor cell
                    int newEff = max(eff, abs(h[r][c] - h[nr][nc]));

                    // Relaxation: update dist if we found a better effort
                    if (newEff < dist[nr][nc])
                    {
                        dist[nr][nc] = newEff;
                        pq.push({newEff, {nr, nc}});
                    }
                }
            }
        }
        // Final effort to reach bottom-right cell
        return dist[rows - 1][cols - 1];
    }
};

/*
KEY-OBSERVATIONS & INSIGHTS:
. dijkstra algo problem
. relaxation: new cost = max(curcost, |parentHieght-nodeheight|)
. push to min_heap
. check for destination during popping, not when relaxing only
. mark visited while popping not pushing
ALGO:
1 src <- 0,0
2 dijkstra algo to find shortest

PROBLEMS:

*/