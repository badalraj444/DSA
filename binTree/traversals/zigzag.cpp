/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        int cnt = 0;

        while (root && !q.empty())
        {
            vector<int> temp;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                root = q.front();
                temp.push_back(root->val);

                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);

                q.pop();
            }
            if (cnt++ % 2)
                reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }

        return ans;
    }
};

/*
1.init ans, tak q, innsert root, cnt = 0
2. while q is not empty
     take temp vector
     n = q.size()
     for i:n
     take element into temp, push left first , right next

     if cnt++%2 reverse temp
     store in ans
3. return ans
*/