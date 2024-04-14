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
    int dfsRecurAlgo(TreeNode* root,bool checkLeft){
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL && checkLeft == true){
            return root->val;
        }

        int leftSum = dfsRecurAlgo(root->left,true);
        int rightSum = dfsRecurAlgo(root->right,false);
         
        return leftSum + rightSum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return dfsRecurAlgo(root,false); 
    }
};