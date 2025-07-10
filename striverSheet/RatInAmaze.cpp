#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> findPath(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<string> ans;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        backtrack(0, 0, grid, ans, "", visited);

        return ans;
    }

private:
    void backtrack(int row, int col, vector<vector<int>> &grid, vector<string> &ans, string path, vector<vector<bool>> &visited)
    {
        if (row == grid.size() - 1 && col == grid.size() - 1 && grid[row][col]==1)
        {
            ans.push_back(path);
            return;
        }

        if (!isAvailable(row, col, grid, visited))
            return;

        visited[row][col] = true;

        backtrack(row + 1, col, grid, ans, path + 'D', visited); //accept-unaccept is happening here! +-1 , visited is just to avoid retracing last to last
        backtrack(row - 1, col, grid, ans, path + 'U', visited);
        backtrack(row, col + 1, grid, ans, path + 'R', visited);
        backtrack(row, col - 1, grid, ans, path + 'L', visited);

        visited[row][col] = false;
    }

    bool isAvailable(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {
        if (row == grid.size() || col == grid.size() || row == -1 || col == -1)
            return false;
        if (visited[row][col])
            return false;
        if (grid[row][col] == 0)
            return false;
        return true;
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    Solution s;
    vector<string> ans = s.findPath(grid);
    for (string s : ans)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}

/*ALGO:
1. init ans vector of string , string path , 2d vector visited bool all false
2. call recursively, backtrack(grid, row,col,ans visited):
   base: if(visited[n-1][n-1])
            store path in ans
            return
    if cell is not acceptable, return
    mark visited
    take cell in path
    for all 4 directions:
         call backtrack(grid, r, c)
    remove cell from path
    unmark visited
3. finally, return ans
bool acceptable(r,c,grid,visited):
   if cell not valide, ret false
   if visited[cell] , ret false
   if grid[cell] = 0, ret false
   ret true*/
/*
KEY-OBSERVATIONS & INSIGHTS:
. start from 0,0 , aim to reach n-1,n-1
. from one cell , go to all 4 directions:
   if cell not valid return back
   if cell not occupied, return back
   if cell blocked, return back
   accept cell(store in path, mark visited true), back track, unaccept(mark visited false, remove from path)
. base: if current cell is n-1, n-1 store path in ans, return
. keep a bool 2d array for cells visited.

PROBLEMS:

*/
