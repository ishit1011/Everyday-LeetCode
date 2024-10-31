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
    bool dfs(TreeNode* root){
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        if(root->left != NULL && root->right != NULL){
            return (root->val == root->left->val + root->right->val);
        }
        bool lft = dfs(root->left);
        bool rght = dfs(root->right);
        return (lft && rght);
    }
    bool checkTree(TreeNode* root) {
        return dfs(root);
    }
};