class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true; // when both are missing
        if(!p || !q) return false; // for case when only one of places missing, not both, it was handled earlier
        bool l = isSameTree(p->left, q->left);
        if(p->val!=q->val) return false;
        bool r = isSameTree(p->right, q->right);

        return (l && r);
    }
};