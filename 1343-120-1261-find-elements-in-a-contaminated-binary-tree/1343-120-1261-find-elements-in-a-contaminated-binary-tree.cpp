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
class FindElements {
public:
    set<int> valSet;
    void dfs(int x, TreeNode* root){
        if(root == NULL) return;
        root->val = x;
        valSet.insert(x);
        dfs(( (2*x) + 1),root->left);
        dfs(( (2*x) + 2),root->right);
        return;
    }

    FindElements(TreeNode* root) {
        int x = 0;
        dfs(x,root);
    }
    
    bool find(int target) {
        // for(auto x : valSet){
        //     cout<<x<<" ";
        // }
        if(valSet.find(target) == valSet.end()) return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */