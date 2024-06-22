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
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> arr;
        queue<TreeNode*> q;
        if(root == NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> row;
            
            while(n > 0){
                TreeNode* temp = q.front();
                row.push_back(temp->val);
                q.pop();

                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
                n--;
            }
            arr.push_back(row);
        }
        for(int i=0; i<arr.size(); i++){
            int n = arr[i].size();
            ans.push_back(arr[i][n-1]);
        }
        return ans;
    }
};