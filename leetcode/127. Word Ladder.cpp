class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        if (!wordset.count(endWord))
            return 0; // endWord must exist in wordList

        unordered_map<string, bool> vis;
        queue<string> q;
        q.push(beginWord);
        vis[beginWord] = true;
        int count = 1; // beginWord is level 1

        // BFS traversal
        while (!q.empty())
        {
            int n = q.size();

            // Process all words at current level
            while (n--)
            {
                string curr = q.front();
                q.pop();

                // Found the end word
                if (curr == endWord)
                    return count;

                // Try all one-letter transformations
                for (int i = 0; i < curr.size(); i++)
                {
                    string temp = curr;
                    for (char ch = 'a'; ch <= 'z'; ++ch)
                    {
                        temp[i] = ch;
                        if (wordset.count(temp) && !vis[temp])
                        {
                            q.push(temp);
                            vis[temp] = true;
                        }
                    }
                }
            }

            // Move to next level
            count++;
        }

        return 0; // No transformation sequence found
    }
};
