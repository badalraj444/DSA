class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();

        // Initialize answer matrix with -1 (unvisited)
        vector<vector<int>> ans(m, vector<int>(n, -1));

        // 4 directions: up, down, left, right
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        queue<pair<int, int>> q;

        // Step 1: Push all cells with 0 into the queue and mark them as distance 0
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({i, j}); // Add zero cell to BFS queue
                    ans[i][j] = 0;  // Distance from 0 to itself is 0
                }
            }
        }

        // Step 2: BFS from all 0s simultaneously (multi-source BFS)
        while (!q.empty())
        {
            auto [i, j] = q.front(); // Current cell
            q.pop();

            for (auto &p : dir)
            { // Check 4 neighbors
                auto [di, dj] = p;
                int ni = i + di; // New row index
                int nj = j + dj; // New column index

                // If in bounds and not visited
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && ans[ni][nj] == -1)
                {
                    ans[ni][nj] = ans[i][j] + 1; // Update distance
                    q.push({ni, nj});            // Add to queue for further exploration
                }
            }
        }

        // Step 3: Return the final distance matrix
        return ans;
    }
};

/*
KEY OBSERVATIONS:
- Each 0 acts as a source; start BFS from all 0s at once (multi-source BFS).
- Propagate distance info layer by layer to neighboring 1s.
- No need for visited array — we use ans[i][j] == -1 to check if visited.

ALGORITHM:
1. Initialize ans[][] with -1.
2. Push all 0s into the queue and set their distance as 0.
3. While queue is not empty:
   a. Pop front cell.
   b. For all 4 directions:
      - If neighbor is unvisited:
         - Set distance = current distance + 1.
         - Push neighbor to queue.
4. Return ans.
*/
