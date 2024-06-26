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
    void inorder(TreeNode* root, vector<int> &v){
        if(root == NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    TreeNode* f(vector<int> &v, int l, int r){
        int mid = (l+r)/2;
        if(l > r) return NULL;
        TreeNode* temp = new TreeNode(v[mid]);
        temp->left = f(v,l,mid-1);
        temp->right = f(v,mid+1,r); 
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        return f(v,0,v.size()-1);
    }
};