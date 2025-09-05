class Solution
{
public:
    int numSubmat(vector<vector<int>> &mat)
    {
        int ans = 0;
        int m = mat.size(), n = mat[0].size();
        // store 1 streak to left
        vector<vector<int>> streak(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // find streak
                if (j == 0)
                    streak[i][j] = mat[i][j];
                else
                {
                    streak[i][j] = (mat[i][j] == 0) ? 0 : streak[i][j - 1] + 1;
                }
                // find number of submatrices possible checking all above cells including current
                int curr = streak[i][j];
                for (int k = i; k >= 0; k--)
                {
                    curr = min(curr, streak[k][j]);
                    if (curr == 0)
                        break;
                    ans += curr;
                }
            }
        }
        // done
        return ans;
    }
};

/*
KEY-OBSERVATIONS & INSIGHTS:
. maths problem. it needs mathematical modelling before you can even think of
soln. . we can count the no of subm from every cell seeing it as the
bottom-right cell of rectangle . we can keep track of number of 1s to left of
every 1-valued cell, storing it in the matr itself . for every cell now, count
as: for all cells along this col, add min(c, c-1) . it is mathematically seen
that this approach includes each possible rectangles and without repetetion

ALGO:
1. find the number of 1s left of each cell valued 1
2. from each cell calculate number of possible subm and add to ans
3. return ans

PROBLEMS:

*/