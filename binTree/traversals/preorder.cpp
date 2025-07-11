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
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         preorder(root, ans);

//         return ans;
//     }
//     void preorder(TreeNode* & root, vector<int>& ans){
//             if(!root) return;
//             ans.push_back(root->val);
//             preorder(root->left, ans);
//             preorder(root->right, ans);
//         }
// };
///////Iterative//////////
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> ans;
        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            if (curr->right)
                st.push(curr->right);
            if (curr->left)
                st.push(curr->left);
        }

        return ans;
    }
};
/*
ALGO:
0. if not root, return {}
1. init ans vect, stack, push root to stack
2. while(st not empty):
    read top node of stack, pop
    if exist, insert first right child (so it comes later)
    if exist,insert left child (last comes first)
3. finally, return ans
*/