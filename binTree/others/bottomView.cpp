/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
  public:
    vector <int> bottomView(TreeNode *root){
      vector <int> ans;
      if(!root)return ans;
      map<int,int>bottomNode;
      queue<pair<TreeNode*, int>>q;
      q.push({root,0});

      while(!q.empty()){
        auto [node,hd] = q.front();
        q.pop();

        bottomNode[hd] = node->data;

        if(node->left)q.push({node->left, hd-1});
        if(node->right)q.push({node->right, hd+1});
      }
      
      for(auto& it: bottomNode){
        ans.push_back(it.second);
      }
      return ans;
    }
};

// 1. init ans, a map to store hd and node val, a queue to store node and hd pair
// 2. push root , 0 innto queue
// 3. while que is not empty:
   
//     unpack pair of top of que, 
//     overwrite the val to hd of current hd
//     push the left and right child if present with adjusted hd

// 4. read the map using iterator, store one by one in ans
// 5. return ans    
