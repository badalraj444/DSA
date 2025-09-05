class Solution
{
public:
    int perfectSum(vector<int> &arr, int target)
    {
        // code here
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int n : arr)
        {
            if (n == 0)
            {
                // x2 all
                for (int i = 0; i <= target; i++)
                    dp[i] = 2 * dp[i];
            }
            else
            {
                for (int i = target; i >= n; i--)
                {
                    dp[i] += dp[i - n];
                }
            }
        }
        return dp[target];
    }
};

/*
KEY-OBSERVATIONS & INSIGHTS:
. a variation of subset sum problem
. try to form target
. instead of yes or no store count of subset sum reaching to target
. dp[s] = dp[s] + dp[s-n]  for all n in array
. for n = 0, app dps double, it can be included or not included so x2

ALGO:
1 init dp for target+1 with count 0 for each
2 dp[o] = 1
3 form dp
4 return dp[target]

PROBLEMS:

*/