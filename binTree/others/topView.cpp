class Solution
{
public:
    vector<int> topView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        // Map to store the first node at every horizontal distance
        map<int, int> topNode;
        queue<pair<TreeNode *, int>> q; // {node, horizontal distance}

        q.push({root, 0});

        while (!q.empty())
        {
            auto [node, hd] = q.front();
            q.pop();

            // Only insert into map if hd is being seen for the first time
            if (topNode.find(hd) == topNode.end())
            {
                topNode[hd] = node->data;
            }

            if (node->left)
                q.push({node->left, hd - 1});
            if (node->right)
                q.push({node->right, hd + 1});
        }

        // Extract values in order of horizontal distance
        for (auto &it : topNode)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};
