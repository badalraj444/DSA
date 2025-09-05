class Solution
{
public:
    // ============================
    // Tabulation (Bottom-Up DP)
    // ============================
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();

        // Convention for tabulation:
        // dp[i][j] = LCS length of first i chars of text1 (text1[0..i-1])
        //                        and first j chars of text2 (text2[0..j-1])
        // Table size: (n+1) x (m+1)
        // Base case: dp[0][*] = dp[*][0] = 0  (empty string vs anything)

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    // If last characters of these prefixes match
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    // Otherwise, take the best by skipping one char
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }

    // ============================
    // Memoization (Top-Down DP)
    // ============================
    /*
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // Convention for memoization:
        // lcs(i, j) = LCS length of text1[0..i] and text2[0..j]
        // Base case: if i == -1 or j == -1 → 0 (empty string reached)
        // State: memo[i][j] stores result for i,j

        vector<vector<int>> memo(n, vector<int>(m, -1));
        return lcs(n - 1, m - 1, text1, text2, memo);
    }

    int lcs(int i, int j, string& text1, string& text2,
            vector<vector<int>>& memo) {
        if (i == -1 || j == -1) return 0; // base case

        if (memo[i][j] != -1) return memo[i][j]; // already computed

        if (text1[i] == text2[j]) {
            // last characters match
            return memo[i][j] = 1 + lcs(i - 1, j - 1, text1, text2, memo);
        } else {
            // skip one character from either string
            return memo[i][j] = max(
                lcs(i - 1, j, text1, text2, memo),
                lcs(i, j - 1, text1, text2, memo)
            );
        }
    }
    */
};
