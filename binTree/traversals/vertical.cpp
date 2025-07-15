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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, vector<pair<int,int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()){
         auto [node, X] = q.front();q.pop();
         auto [row,col] = X;
            nodes[col].push_back({row, node->val});
            if(node->left)q.push({node->left, {row+1, col-1}});
            if(node->right)q.push({node->right, {row+1, col+1}});
        }

        for(auto& it:nodes){
            vector<int> temp;
            sort(it.second.begin(),it.second.end());
            for(auto pr:it.second){
              auto [row,val] = pr;
              temp.push_back(val);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

//the nodes should be grouped and sorted in first column order:ascending order... 
                                    //   then if same, row order: ascending order...
                                    //   then if same, values order: ascending order...
//  maps for columns: int, vector of pairs
// use pair for storing row, and values   , 
// sort vector of pairs
// iterate over map, for each.. vector of pair, get the second value , store all in a vector, push to ans  
//            ret ans                  