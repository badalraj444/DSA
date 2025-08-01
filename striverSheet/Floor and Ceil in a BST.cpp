class Solution
{
public:
    vector<int> floorCeilOfBST(TreeNode *root, int key)
    {
        vector<int> ans;
        ans.push_back(findFloor(root, key)); // Floor first
        ans.push_back(findCeil(root, key));  // Ceil second
        return ans;
    }

private:
    int findFloor(TreeNode *node, int key)
    {
        int floor = -1;
        while (node)
        {
            if (node->data == key)
                return node->data;
            else if (node->data < key)
            {
                floor = node->data; // potential floor
                node = node->right; // unlike you d do in searching, reverse direction
            }
            else
            {
                node = node->left;
            }
        }
        return floor;
    }

    int findCeil(TreeNode *node, int key)
    {
        int ceil = -1;
        while (node)
        {
            if (node->data == key)
                return node->data;
            else if (node->data > key)
            {
                ceil = node->data; // potential ceil
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        return ceil;
    }
};
