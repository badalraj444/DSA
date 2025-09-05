class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
       // code here
       int n = arr.size();
       vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        return dfs(0,sum, arr, dp);
        
    }
    bool dfs(int idx, int need, vector<int> &arr, vector<vector<int>>& dp){
        if(need <0 ) return false;
        if(need == 0) return true;
        if(idx == arr.size()) return false;
        //dp
        if(dp[idx][need] != -1) return dp[idx][need];
        //recursive
        bool take = dfs(idx+1, need-arr[idx], arr, dp);
        bool skip = dfs(idx+1, need, arr, dp);
        return dp[idx][need] = take || skip;
    }
};

/*
KEY-OBSERVATIONS & INSIGHTS:
. every element can be taken or not taken. try all combinations and see if possible

ALGO:
1 dfs with no element chosen , and needed <- sum, ind <- 0
2 function dfs:
    if needed is negative, return false
    if needed is zero , return true
    else
      take next 
      not take next 
      and try both if any gives true
3 add dp : needed more and subarray index available    
      

PROBLEMS:

*/