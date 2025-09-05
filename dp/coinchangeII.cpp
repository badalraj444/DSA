class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1; // base
        for (int coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};
// MEMOISATION
//  class Solution {
//  public:
//      int change(int amount, vector<int>& coins) {
//          int n = coins.size();
//          // memo[index][remaining] = number of ways
//          vector<vector<long long>> memo(n, vector<long long>(amount + 1, -1));
//          return dfs(0, amount, coins, memo);
//      }

//     long long dfs(int idx, int remaining, vector<int>& coins, vector<vector<long long>>& memo) {
//         // base cases
//         if (remaining == 0) return 1;           // found a valid way
//         if (idx == coins.size()) return 0;      // no coins left
//         if (memo[idx][remaining] != -1) return memo[idx][remaining];

//         long long ways = 0;

//         // Option 1: take the current coin (if possible)
//         if (coins[idx] <= remaining) {
//             ways += dfs(idx, remaining - coins[idx], coins, memo);
//         }

//         // Option 2: skip the current coin
//         ways += dfs(idx + 1, remaining, coins, memo);

//         return memo[idx][remaining] = ways;
//     }
// };

/*
KEY-OBSERVATIONS & INSIGHTS:
tabulation:
. subset sum variation: try finding how many ways subset can be formed
. initially all 0 then process every coin in forward direction as it can be reused.
. add : number of new connection
memoisation:
. backtrack every combinatino and when amount is reached count++, if overran, prune

algorithtm

PROBLEMS:
! final result is guaranteed to be in int but intermediate dp values exceeded even long long. needed unsigned long long
*/