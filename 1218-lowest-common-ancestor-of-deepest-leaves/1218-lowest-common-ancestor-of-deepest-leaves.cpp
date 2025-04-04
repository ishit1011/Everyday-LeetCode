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
    pair<int, TreeNode*> dfsPreOrder(TreeNode* node) {
        if (!node){
            return {0, nullptr};
        }
        // L-R-N
        auto leftSubtree = dfsPreOrder(node->left);
        auto rightSubtree = dfsPreOrder(node->right);

        if (leftSubtree.first == rightSubtree.first)
            return {leftSubtree.first + 1, node};
        else if (leftSubtree.first > rightSubtree.first)
            return {leftSubtree.first + 1, leftSubtree.second};
        else
            return {rightSubtree.first + 1, rightSubtree.second};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfsPreOrder(root).second;
    }
};