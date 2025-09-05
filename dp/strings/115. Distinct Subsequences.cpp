class Solution {
    const int prime = 1e9 + 7;
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        // dp[i][j] = number of ways to form t[0..j-1] from s[0..i-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base case: empty target can always be formed
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        // Fill the table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%prime;
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[m][n];
    }
};


//MEMOISATION:
// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int m = s.size();
//         int n = t.size();
//         // dp[i][j] = ways to form t[0..j-1] from s[0..i-1]
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
//         return countSubseq(s, t, m, n, dp);
//     }

// private:
//     int countSubseq(string &s, string &t, int i, int j, vector<vector<int>>& dp) {
//         // Base cases
//         if (j == 0) return 1;   // empty target always possible
//         if (i == 0) return 0;   // empty source can't form non-empty target

//         if (dp[i][j] != -1) return dp[i][j];

//         if (s[i-1] == t[j-1]) {
//             // Use current char OR skip it
//             dp[i][j] = countSubseq(s, t, i-1, j-1, dp) + countSubseq(s, t, i-1, j, dp);
//         } else {
//             // Must skip current char of s
//             dp[i][j] = countSubseq(s, t, i-1, j, dp);
//         }
//         return dp[i][j];
//     }
// };



/*
KEY-OBSERVATIONS & INSIGHTS:
. brute force, overlapping, optimal substructure = dp
. if chars match, we get two ways of trying to match. match upto curr of both(hence equivalent to just match upto last of both) and match upto last of source with curr of target
ALGO:
. recursion:
  base: 
     ncs(x,0) = 1 for all x : empty string is always a part of any string
     ncs(0,y) = 0 for all y>0: non-empty string cannot be  part of an empty string
  recurrence: 
    if(s[x]==t[y]) ncs(x,y) = ncs(x-1,y-1) + ncs(x-1,y)
    else ncs(x,y) = ncs(x-1,y-1)

*/