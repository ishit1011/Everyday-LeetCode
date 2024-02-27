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
    int maxDepth(TreeNode* root){
        int maxLt, maxRt;
        if(root == NULL){
            return 0;
        }
        maxLt = maxDepth(root->left);
        maxRt = maxDepth(root->right);

        return (max(maxLt,maxRt) + 1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int op1, op2, op3;
        if(root == NULL){
            return 0;
        }
        op1 = diameterOfBinaryTree(root->left);
        op2 = diameterOfBinaryTree(root->right);
        op3 = maxDepth(root->left) + maxDepth(root->right) ;
        return max(op3, max(op1,op2));
    }
};