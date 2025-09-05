#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
  public:
    string lcs(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i-1] == str2[j-1]) 
                    dp[i][j] = 1 + dp[i-1][j-1]; // match → extend LCS
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // skip one char
            }
        }

        // Reconstruct one LCS string
        string res;
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (str1[i-1] == str2[j-1]) {
                res += str1[i-1]; // part of LCS
                i--; j--;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                i--; // move up
            } else {
                j--; // move left
            }
        }

        reverse(res.begin(), res.end()); // reverse to get correct order
        return res;
    }
};

// ---------- MAIN FUNCTION ----------
int main() {
    Solution sol;
    string s1 = "ABCBDAB";
    string s2 = "BDCAB";
    
    string ans = sol.lcs(s1, s2);
    cout << "LCS of \"" << s1 << "\" and \"" << s2 << "\" is: " << ans << endl;
    
    return 0;
}
