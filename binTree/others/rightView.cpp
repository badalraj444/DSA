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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*>q;
        q.push(root);
        while(root && !q.empty()){
            //get last 
            int x = q.back()->val;
            
            int n = q.size();
            while(n--){
              root = q.front(); q.pop();
              if(root->left)q.push(root->left);
              if(root->right)q.push(root->right);
            }

            ans.push_back(x);
            
        }
        return ans;
    }
};
//it is simply the last node of every level
//stop at every level, read and store the val of node at last of queue