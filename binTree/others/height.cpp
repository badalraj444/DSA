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
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1 + max(lh, rh);
    }
};
//********************ITERATIVE METHOD(inorder traversal)*********************
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         int cnt = 0;
//         int ans = 0;
//         stack<TreeNode*>st;
//         while(root || !st.empty()){
//            while(root){
//             cnt++;
//             root->val = cnt;
//             st.push(root);
//             root = root->left;
//             ans = max(ans,cnt);
//            }
//            root = st.top();
//            st.pop();
//            cnt = root->val;
//            root = root->right;
//         }
//         return ans;
//     }
// };
// use a count variable to inc for push
// use a and var as max of count and itself
// visit every branch, you cannot determine longest branch