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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        if(root == NULL){
            return ans;
        }

        while(!q.empty()){
            int n = q.size();
            vector<int> row;

            while(n--){
                TreeNode* temp = q.front();
                row.push_back(temp->val);
                q.pop();
                
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }
            ans.push_back(row);   
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};