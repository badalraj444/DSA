/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
 * };
 **/

class Solution
{
public:
    // Check if the node is a leaf (no children)
    bool isLeaf(TreeNode *node)
    {
        return !node->left && !node->right;
    }

    // Add all nodes from the left boundary (excluding leaves)
    void addLeftBoundary(TreeNode *node, vector<int> &res)
    {
        TreeNode *curr = node->left;
        while (curr)
        {
            if (!isLeaf(curr))
                res.push_back(curr->data);
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    // Add all leaf nodes from left to right
    void addLeaves(TreeNode *node, vector<int> &res)
    {
        if (!node)
            return;
        if (isLeaf(node))
        {
            res.push_back(node->data);
            return;
        }
        addLeaves(node->left, res);
        addLeaves(node->right, res);
    }

    // Add all nodes from the right boundary (excluding leaves), in reverse order
    void addRightBoundary(TreeNode *node, vector<int> &res)
    {
        TreeNode *curr = node->right;
        vector<int> temp;
        while (curr)
        {
            if (!isLeaf(curr))
                temp.push_back(curr->data);
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        // Reverse and add to result
        for (int i = temp.size() - 1; i >= 0; --i)
        {
            res.push_back(temp[i]);
        }
    }

    // Main function to return boundary traversal in anti-clockwise direction
    vector<int> boundary(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;

        // Add root if it's not a leaf (it will be added as leaf anyway)
        if (!isLeaf(root))
            res.push_back(root->data);

        addLeftBoundary(root, res);  // Step 1: Left boundary
        addLeaves(root, res);        // Step 2: All leaves
        addRightBoundary(root, res); // Step 3: Right boundary (in reverse)

        return res;
    }
};
