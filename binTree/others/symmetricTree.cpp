class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSym(root->left, root->right);
    }
    private:
    bool isSym(TreeNode* n1, TreeNode* n2){
        if(!n1 && !n2) return true;
        if(!n1 || !n2)return false;

        if(n1->val!=n2->val) return false;
        
        return (isSym(n1->left, n2->right) && isSym(n1->right, n2->left));
    }
};

//travel right in one sub tree, left in another. use recursion to fork pointers