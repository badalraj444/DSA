class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == word[0]) {
                    if (dfs(board, word, visited, row, col, 0))
                        return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited,
             int row, int col, int index) {
        // Base case: full word matched
        if (index == word.size()) return true;

        // Bounds and match check
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
            return false;
        if (visited[row][col] || board[row][col] != word[index])
            return false;

        // Mark current cell visited
        visited[row][col] = true;

        // Explore 4 directions
        bool found = dfs(board, word, visited, row + 1, col, index + 1) ||
                     dfs(board, word, visited, row - 1, col, index + 1) ||
                     dfs(board, word, visited, row, col + 1, index + 1) ||
                     dfs(board, word, visited, row, col - 1, index + 1);

        // Backtrack
        visited[row][col] = false;

        return found;
    }
};
/*
ALGO:
1. init a temp curr vector of string, global ans to store ans
2. start from all possible places where first char match
3. call recursively,void backtrack(current position, next char index, board,
ans): base case: if ans==true return if word found(expected==''), set anwer to
true, return for all 4 directions: check if index in range check if char is
lower case check if char == expected , expectd = word[i] if yes, call backtrack
for i+1 and from current position else make curr char upper case, return

4. finally, return ans

KEY-OBSERVATIONS & INSIGHT
. classic backtracking problem
. if how many out of 4 directions are available can be determined, all
possiblities can be explored . but must ensure not travelling taking an element
twice, and not travelling back the same path . start position : one by one all
elements . keep exploring a branch untill word found or word deviates or all
possiblities checked n not found . if found, return . if deviation, take a step
back and explore other possiblities


PROBLEMS:
   how to check not visiting a visited element again
   ----- as you visit elements, convert them to upper case. travel only in lower
cases. while returning, restore last travelled to lower case before backtracking
   how to not travel back : same upper idea will take case
*/