// User function Template for C++

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        if (start == end)
            return 0; // edge case: already at destination

        const int size = 1e5;              // we only care about numbers modulo 1e5
        vector<bool> visited(size, false); // track visited states
        queue<int> q;

        q.push(start);
        visited[start] = true; // mark start as visited
        int level = 0;         // BFS level -> number of multiplications

        while (!q.empty())
        {
            int k = q.size(); // process one BFS layer
            for (int i = 0; i < k; i++)
            {
                int u = q.front();
                q.pop();

                if (u == end)
                    return level; // found the destination

                // try all possible multiplications
                for (int dv : arr)
                {
                    int v = (u * dv) % size;
                    if (visited[v])
                        continue; // skip if already visited
                    q.push(v);
                    visited[v] = true; // mark visited when enqueued
                }
            }
            level++; // increment step count after one full layer
        }
        return -1; // end not reachable
    }
};

/*
-----------------------------------------
Observations & Ideas
-----------------------------------------
1. BFS is the right choice:
   - Each multiplication is one step. step size is 1 -> uniform edge length
   - BFS ensures the shortest path (minimum multiplications).

2. Why modulo 1e5?
   - States are bounded to 0...99999.
   - Prevents infinite growth of numbers.

3. `visited[v]` is marked when pushing into the queue:
   - Prevents duplicates in the queue.
   - Avoids exponential blow-up (TLE).

4. Edge case handled:
   - If `start == end`, return 0 immediately.

5. Complexity:
   - Time: O(N * M), where N = 1e5, M = size of arr.
   - Space: O(1e5) for visited + queue.

6. Alternatives:
   - Instead of `level` + double loop, could store (node, steps) in queue.
   - Or use `vector<int> dist(size, -1)` to keep track of steps directly.

7. Limitation:
   - If arr is large, BFS can still be heavy, but bounded by 1e5 states.
*/
