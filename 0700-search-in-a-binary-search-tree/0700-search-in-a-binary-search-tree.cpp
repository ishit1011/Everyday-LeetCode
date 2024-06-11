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
    TreeNode* searchBST(TreeNode* root, int k) {
        if(root == NULL){
            return root;
        }
        if(k == root->val){
            return root;
        }
        if(k > root->val){
            return searchBST(root->right,k);
        }
        if(k < root->val){
            return searchBST(root->left,k);
        }
        return root;
    }
};