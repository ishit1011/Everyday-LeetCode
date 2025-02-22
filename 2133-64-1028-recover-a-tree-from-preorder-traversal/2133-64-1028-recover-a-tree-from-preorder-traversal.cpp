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
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();

        vector<pair<int,int>> numLvl;
        int idx= 0;
        while(idx < n){
            int dashCnt = 0;
            while(idx < n && traversal[idx] == '-'){
                dashCnt++;
                idx++;
            }
            int val = 0;
            while(idx < n && isdigit(traversal[idx])){
                val = val * 10 + (traversal[idx] - '0');
                idx++;
            }
            numLvl.push_back({val,dashCnt});
        }

        TreeNode* root = NULL;
        stack<pair<TreeNode*,int>> stk;
        for(auto x : numLvl){
            int depth = x.second;
            int val = x.first;

            while(!stk.empty() && depth <= stk.top().second){
                stk.pop();
            }
            TreeNode* node = new TreeNode(val);
            if(stk.empty()){
                root = node;
            }
            else{
                TreeNode* parent = stk.top().first;
                if(!parent->left) parent->left = node;
                else parent->right = node;
            }
            stk.push({node,depth});
        }
        return root;
    }
};