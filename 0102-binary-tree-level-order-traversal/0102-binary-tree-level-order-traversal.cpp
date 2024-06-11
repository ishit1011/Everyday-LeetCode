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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        if(root == NULL){
            return ans;
        }

        while(!q.empty()){
            int n = q.size();
            vector<int> row;

            while(n > 0){
                TreeNode* first = q.front();
                row.push_back(first->val);
                q.pop();

                if(first->left != NULL){
                    q.push(first->left);
                }
                if(first->right != NULL){
                    q.push(first->right);
                }
                n--;
            }

            ans.push_back(row);
        }
        return ans;
    }
};