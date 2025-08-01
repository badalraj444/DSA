class Solution
{
public:
    int checkChildrenSum(TreeNode *root)
    {
        // Base case: null or leaf node is valid
        if (!root || (!root->left && !root->right))
            return 1;

        // Get child values
        int leftVal = root->left ? root->left->val : 0;
        int rightVal = root->right ? root->right->val : 0;

        // Check current node and recurse
        if (root->val == leftVal + rightVal &&
            checkChildrenSum(root->left) &&
            checkChildrenSum(root->right))
        {
            return 1;
        }

        return 0;
    }
};
