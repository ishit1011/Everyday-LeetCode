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
    int dfs(TreeNode* root,int pathSum){
        if(root == NULL){
            return 0; 
        }

        pathSum = pathSum * 10 + root->val;

        if(root->left == NULL && root->right == NULL){
            return pathSum;
        }
        return dfs(root->left,pathSum) + dfs(root->right,pathSum); 
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};

// check for  :
//  1. Leaf Node
//  2. No. of levels