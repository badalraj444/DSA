// LEETCODE 188: Best Time to Buy and Sell Stock IV
// DP Approach with "transactions done so far" (buy=even, sell=odd)

// ----------------------------
// TABULATION
// ----------------------------
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int trans = 2 * k;  // max steps = 2*k (buy+sell pairs)
        vector<vector<int>> dp(n+1, vector<int>(trans+1, 0));

        // dp[i][j] = max profit starting from day i with j transactions done
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < trans; j++) {
                if (j % 2 == 0) { // even -> buy
                    dp[i][j] = max(-prices[i] + dp[i+1][j+1], dp[i+1][j]);
                } else { // odd -> sell
                    dp[i][j] = max(prices[i] + dp[i+1][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[0][0];  // start at day 0, with 0 transactions done
    }
};

// ----------------------------
// MEMOIZATION (same logic, top-down)
// ----------------------------
// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> memo(n, vector<int>(2*k+1, -1));
//         return profit(0, 0, 2*k, prices, memo);
//     }
// private:
//     int profit(int i, int trans, int maxTrans, vector<int>& prices, vector<vector<int>>& memo) {
//         if (i == prices.size() || trans == maxTrans) return 0;
//         if (memo[i][trans] != -1) return memo[i][trans];
//
//         if (trans % 2 == 0) { // buy
//             int buy = -prices[i] + profit(i+1, trans+1, maxTrans, prices, memo);
//             int skip = profit(i+1, trans, maxTrans, prices, memo);
//             return memo[i][trans] = max(buy, skip);
//         } else { // sell
//             int sell = prices[i] + profit(i+1, trans+1, maxTrans, prices, memo);
//             int skip = profit(i+1, trans, maxTrans, prices, memo);
//             return memo[i][trans] = max(sell, skip);
//         }
//     }
// };

// ----------------------------
// KEY OBSERVATIONS
// ----------------------------
/*
1. Each buy and sell is treated as one transaction.
   - Max = 2*k transactions total.
   - Even index → allowed to BUY
   - Odd index  → allowed to SELL

2. State:
   dp[i][j] = max profit from day i with j transactions already done.

3. Transitions:
   - If j is even → buy:  max(-price + dp[i+1][j+1], skip)
   - If j is odd  → sell: max(+price + dp[i+1][j+1], skip)

4. Base cases:
   - If i == n (end of days) → 0
   - If j == 2*k (all allowed transactions used) → 0

5. Complexity:
   - Time:  O(n * 2k)
   - Space: O(n * 2k)
   - Can be optimized to O(2k) with rolling arrays.
*/
