class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return dia;
    }
    int dia = 0;
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);

        dia = max(dia, (l + r)); // in case it is a potential answer, write ans

        return 1 + max(l, r);
    }
};