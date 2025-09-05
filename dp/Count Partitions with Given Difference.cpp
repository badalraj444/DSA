class Solution
{
public:
    int countPartitions(vector<int> &arr, int d)
    {
        // Code here
        long long sum = accumulate(arr.begin(), arr.end(), 0);
        vector<int> dp(sum + 1, 0);
        // find subset sums
        dp[0] = 1;
        for (int n : arr)
        {
            if (n == 0)
            {
                for (int i = 0; i <= sum; i++)
                    dp[i] *= 2;
            }
            else
            {
                for (int i = sum; i >= n; i--)
                {
                    dp[i] += dp[i - n];
                }
            }
        }
        // count all whose diff is d
        int count = 0;
        for (int s1 = 0; s1 <= sum; s1++)
        {
            int s2 = sum - s1;
            if (s1 - s2 == d)
                count += dp[s1];
        }
        // done
        return count;
    }
};

/*
KEY-OBSERVATIONS & INSIGHTS:
. a variation of subset sum problem
. find all sums possible
. count sums for which diff of sum1 as sum and sum2 as total-sum1 is d
. i must not only check sums possible, but count how many ways possible

ALGO:
1 find total
2 find all subset sums possible as their count : 0 for never
3 count sums for which sum2 is less than d exactly

PROBLEMS:
sum1 should be greater than equal to sum2. means? should i not take abs

*/