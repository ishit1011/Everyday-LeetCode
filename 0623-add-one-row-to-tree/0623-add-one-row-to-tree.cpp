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
    TreeNode* solve(TreeNode* root, int val, int depth){
        if(root == NULL){
            return root;
        }
        if(depth == 2){
            TreeNode* temp1 = new TreeNode(val);
            TreeNode* temp2 = new TreeNode(val);
            TreeNode* leftSubtree = root->left;
            TreeNode* rightSubtree = root->right;
            root->left = temp1;
            root->right = temp2;
            temp1->left = leftSubtree;
            temp2->right = rightSubtree;
            return root;
        }
        solve(root->left,val,depth-1);
        solve(root->right,val,depth-1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* ptr = new TreeNode(val);
            ptr->left = root;
            return ptr;
        }
        solve(root,val,depth);
        return root;
    }
};