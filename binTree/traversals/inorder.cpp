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
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         inorder(ans,root);
//         return ans;
//     }
//     void inorder(vector<int>&ans , TreeNode* root){
//         if(!root)return;
//         inorder(ans , root->left);
//         ans.push_back(root->val);
//         inorder(ans , root->right);
//     }
// };
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode* temp = root;

        while(temp || !st.empty()){
            while(temp){ //see it as pushing in stack the left side
                st.push(temp);
                temp = temp->left;
            }
            temp = st.top(); st.pop();
            ans.push_back(temp->val); // see it as reading the curr node
           temp = temp->right; // see it as pushing right side in stack.. (in next iteration)
        }


        return ans;
    }
};
//the key is understanding when will the root of any sub tree print: it will print after its left child has completed ie it gets null due to temp=temp->right. it uses the stack to get the
//parent root. and it will not go down again to the left side in while loop because it is hitting due to end of left side children.. temp being nullptr