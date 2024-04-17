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
    string smallestStr = "";
    void dfsSolve(TreeNode* root, string currStr){
        if(root == NULL){
            return;
        }
        currStr = char(root->val + 'a') + currStr;
        if(root->left == NULL && root->right == NULL){
            if(smallestStr == "" || currStr < smallestStr)
            smallestStr = currStr;
        }
        if(root->left){
            dfsSolve(root->left,currStr);
        }
        if(root->right){
            dfsSolve(root->right,currStr);
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        dfsSolve(root,"");
        return smallestStr;
    }
};