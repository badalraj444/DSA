class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int m = image.size();
        int n = image[0].size();
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        int startcol = image[sr][sc];
        if (startcol == color)
            return image;
        q.push({sr, sc});
        image[sr][sc] = color;
        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();
            for (auto &p : dir)
            {
                auto [di, dj] = p;
                int ni = i + di;
                int nj = j + dj;
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && image[ni][nj] == startcol)
                {
                    image[ni][nj] = color;
                    q.push({ni, nj});
                }
            }
        }

        return image;
    }
};

// implement bfs simply