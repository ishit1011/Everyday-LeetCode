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
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int currLvlSize = q.size();
            int maxima = INT_MIN;
            for(int i=0; i<currLvlSize; i++){
                TreeNode* topNode = q.front();
                q.pop();
                maxima = max(maxima, topNode->val);
                if(topNode->left != NULL) q.push(topNode->left);
                if(topNode->right != NULL) q.push(topNode->right);
            }
            ans.push_back(maxima);
        }
        return ans;
    }
};