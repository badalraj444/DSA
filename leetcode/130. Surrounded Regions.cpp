class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' && onEdge(i, j, m, n))
                {
                    board[i][j] = 'E';
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();
            for (auto &[di, dj] : dir)
            {
                int ni = i + di, nj = j + dj;
                if (!isValid(ni, nj, m, n))
                    continue;
                if (board[ni][nj] == 'O')
                {
                    board[ni][nj] = 'E';
                    q.push({ni, nj});
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'E')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    bool onEdge(int i, int j, int m, int n)
    {
        return (i == 0 || j == 0 || i + 1 == m || j + 1 == n);
    }
    bool isValid(int i, int j, int m, int n)
    {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
};

/*
KEY-OBSERVATIONS & INSIGHTS:
. instead of finding surrounder o, find edge o, and all those connected to it
. except those make all x

ALGO:
1. find all edge o, make them 'e' and use multi-source bfs to find connected 0s and do the same
2. finally, convert all 1. o to x and 2. e to o

PROBLEMS:

*/