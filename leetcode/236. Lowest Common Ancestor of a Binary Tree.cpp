
/*
KEY-OBSERVATIONS & INSIGHTS:
. dfs
. the answer node will have this unique property: two of left subtree, right subtree, parent will have the nodes we are looking for. both will not be present in one of the sub trees.
. since the nodes are  unique, we need not check which ones are found, just complete the number ie we need to get two. both of them will definetly be different

ALGO:
dfs:
check if left has something
check if right has something
check if itself has something

check if at least two points have somehting, write ans
return up if this subtree has something: ie in left or right, or mid(itself)

PROBLEMS:

*/
//**************clean:
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        dfs(root, p, q);
        return ans;
    }

private:
    TreeNode* ans;

    bool dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node) return false;

        bool left = dfs(node->left, p, q);
        bool right = dfs(node->right, p, q);
        bool mid = (node == p || node == q);

        if ((mid && left) || (mid && right) || (left && right)) {
            ans = node;
        }

        return mid || left || right;
    }
};
