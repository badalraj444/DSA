class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>> ans;
         vector<string> board(n,string(n,'.'));
         backtrack(n, 0,ans,board);

         return ans;
    }
private:
    void backtrack(int& n, int row, vector<vector<string>>& ans,vector<string>& board ){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int c = 0; c<n; c++){
            if(isSafe(row,c,board)){
                board[row][c] = 'Q';
                backtrack(n,row+1,ans,board);
                board[row][c] = '.';
            }
        }
    }

    bool isSafe(int row, int col,vector<string>& board ){
        // //if row not in range ret false
        // if(row>=board.size())return false;
        //check column , only upwards
        for(int r=0; r<=row; r++){
            if(board[r][col]=='Q')return false;
        }
        //check left upper diagonal
        int r = row, c = col;
        while(r>=0 && c>=0){
            if(board[r--][c--]=='Q')return false;
        }
        //check right upper diagonal
        r = row; c = col;
        while(r>=0 && c<=board[0].size()){
            if(board[r--][c++]=='Q')return false;
        }
        // true after all cases passed
        return true;
    }  
};

/*
ALGO:
1. init 2d ans vector of strings, a 2d vector of chars mimicing board n x n initialised with .
. - blank
q - queen
2. call recursively, backtrack(n,row:0,col,ans, board):
   base: if row == n
            convert board to ans string
            store in ans
            return
    for all colms c : 
      if place safe:
        mark Q in place board[row][c]
        backtrack(n, c, row+1,placed,ans,board)
        mark back . the place  board[row][c]     
finally return ans
isSafe(row, col, board){
    if 'Q in col  ret false
    if 'Q in upper left dia ret false
    if 'Q in upper right dia ret false
    return true
}

KEY-OBSERVATIONS & INSIGHTS:
. all rows must have one and only one queen! so i can call backtrack row-wise
. queens can attack straight, diagonally.
. can keep record of positions not available, as I place queens
. after inserting a queen, mark whole col, diagonals( +-, --) not-available
. i can place a queen on available places of next row searching col wise one by one, update the board for places not available
  and then proceed, if violation , return 
. return when number of queens set == n (row = n, starting row from 0), store in ans,undo last step, backtrack for other possiblities

*/