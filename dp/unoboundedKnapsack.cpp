// User function Template for C++

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
         int n = val.size();
         int W = capacity;

        // dp[i][j] = maximum value achievable from items i...n-1
        // with current weight = j
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        // Base case: dp[n][*] = 0
        // (if no items left, max value = 0 for all weights)

        // Fill table bottom-up
        for (int i = n - 1; i >= 0; --i)
        { // iterate items backwards
            for (int j = W; j >= 0; --j)
            {                            // iterate weights backwards
                int skip = dp[i + 1][j]; // option 1: skip item
                int take = 0;
                if (j + wt[i] <= W)
                { // option 2: take item (if valid)
                    take = val[i] + dp[i][j + wt[i]];
                }
                dp[i][j] = max(skip, take); // best of two choices
            }
        }

        // Answer is max value starting from 0th item, weight 0
        return dp[0][0];
    }
};

/*
KEY-OBSERVATIONS & INSIGHTS:
. similar to 01 knapsack but here infinite takes possible. so we can try all combos
. not greedy because 
🔹 Why it Works

When you don’t move i → i+1 on take:

You’re saying: “I’ve taken this item, but I still have the option to take it again in the future.”

That exactly models unbounded knapsack.

So just by that one line change, your DP now supports infinite supply of items.


*/