class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> parts;
        backtrack(s, 0, parts, ans);
        return ans;
    }
private:
    void backtrack(string& s, int start, vector<string>& parts, vector<vector<string>>& ans) {
        if (start == s.size()) {
            ans.push_back(parts);
            return;
        }
        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s, start, end)) {
                parts.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, parts, ans);
                parts.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};
/*
ALGO:
1. init 2d vec ans, 1d vec partitions
2. call recursively: backtrack:
   1. base: 
            if end to string, store in ans
            return
    2. partition the next char,if last substring formed is not a palindrome ->return, else call backtrack for next char
    3. undo last partioning, call backtrack considering next char     
3. finally, return ans
KEY-OBSERVATIONS:
. its about finding all possible partitionings such that the substrings are palindrome
. find all possible partitionings, check if substrings are palindrome, add to answer the current partitoning
. all possiblities of partitioning can be found using backtracking
. partition only if last substring formed is a palindrome
. need separate function to check isPalindrome? or do I?
. classical backtracking problem
. close branches as soon as the last substring is not a palindrome
. if no more string to process, store in answer 2d vector
. need a ptr to track last parition point. new subs = last-i


PROBLEMS:
? how to check palindrome efficiently---- using left and right pointers
? how to mark a partition combination---- using a temp vector of substrings
*/