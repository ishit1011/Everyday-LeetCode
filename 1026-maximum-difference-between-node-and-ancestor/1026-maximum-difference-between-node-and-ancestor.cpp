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
    int diff = 0;

    void dfs(TreeNode* root, int maxDiff, int minDiff){
        if(!root) return;

        diff = max(diff, max(abs(root->val-maxDiff), abs(root->val-minDiff)));
        minDiff = min(minDiff, root->val);
        maxDiff = max(maxDiff,root->val);
        dfs(root->left, maxDiff, minDiff);
        dfs(root->right, maxDiff, minDiff);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        int maxVal = root->val, minVal = root->val;
        dfs(root, maxVal, minVal);
        return diff;
    }
};