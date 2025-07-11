class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;

        if (abs(height(root->left) - height(root->right)) > 1)
            return false;

        return (isBalanced(root->left) && isBalanced(root->right));
    }

private:
    int height(TreeNode *&root)
    {
        if (!root)
            return 0;
        return 1 + (max(height(root->left), height(root->right)));
    }
};