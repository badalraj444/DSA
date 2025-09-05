class Solution {
    int limit;
    int n;
    vector<int> Vl;
    vector<int> Wt;
    vector<vector<int>> dp; // dp[idx][w] = best value from idx onwards with current weight w

  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        n = val.size();
        limit = W;
        Vl = val;
        Wt = wt;
        dp.assign(n + 1, vector<int>(W + 1, -1)); // initialize with -1
        return dfs(0, 0);
    }

    int dfs(int idx, int w) {
        // base case: no more items
        if (idx == n) return 0;

        // if already computed
        if (dp[idx][w] != -1) return dp[idx][w];

        // skip this item
        int skip = dfs(idx + 1, w);

        // take this item (if within limit)
        int take = 0;
        if (w + Wt[idx] <= limit) {
            take = Vl[idx] + dfs(idx + 1, w + Wt[idx]);
        }

        return dp[idx][w] = max(skip, take);
    }
};


/*
KEY-OBSERVATIONS & INSIGHTS:
. no general rule for local choice , i must try all combos. 
 hence it needs backtracking. and as it can have substurcture and overlapping. it can
 be solved using dynamic programming
. even if weight is more, by skipping whenever it is more , we can always reach the end.
 hence find max at end only
 . state depends only on current index and current weight not on what val is available till now
 
ALGO:
MEMOISATION:
 try all combos of take untake 
 take = if feasible (curr + next) else 0
 skip = next
 ret max(take, skip)

*/