// User function Template for C++

class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        // code here
        int n = price.size();
        int W = n;

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
                if (j + (i + 1) <= W)
                { // option 2: take item (if valid)
                    take = price[i] + dp[i][j + i + 1];
                }
                dp[i][j] = max(skip, take); // best of two choices
            }
        }

        // Answer is max value starting from 0th item, weight 0
        return dp[0][0];
    }
};

// 👉 Rod Cutting is literally the Unbounded Knapsack problem in disguise.

// 🔹 Mapping Rod Cutting → Unbounded Knapsack

// Rod Cutting Problem:

// You have a rod of length n.

// You can cut it into pieces of any length 1 … n.

// Each length i has a price price[i-1].

// You want to maximize revenue.

// Unbounded Knapsack Problem:

// Capacity = n (the rod length).

// Items:

// weight = length of cut (i+1)

// value = price of that length (price[i])

// Infinite supply (you can cut as many pieces of length i+1 as you want).

// Maximize value.