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
    string solve(TreeNode* root, unordered_map<string,int>& mp, vector<TreeNode*>& ans){
        if(!root) return "";

        string lft = solve(root->left,mp,ans);
        string rght = solve(root->right,mp,ans);
        
        string temp = to_string(root->val) + "," + lft + "," + rght;
        mp[temp]++;
        if(mp[temp] == 2){
            ans.push_back(root);
        }
        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> mp;
        vector<TreeNode*> ans;
        solve(root,mp,ans);
        return ans;
    }
};