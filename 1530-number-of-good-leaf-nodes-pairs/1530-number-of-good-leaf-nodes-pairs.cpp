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
    vector<int> dfs(TreeNode* node, int distance, int& cnt){
        if(node == NULL){
            return {};
        } 
        if(node->left == NULL && node->right == NULL){
            return {1};
        }
        // Pre-order Traversal
        // Left
        vector<int> leftVec = dfs(node->left,distance,cnt);
        // Right
        vector<int> rightVec = dfs(node->right,distance,cnt);
        // Node
        for(auto it1 : leftVec){
            for(auto it2 : rightVec){
                if(it1 + it2 <= distance){
                    cnt++;
                }
            }
        }
        vector<int> nodeVec;
        for(auto l : leftVec){
            if(l + 1 < distance) nodeVec.push_back(l + 1);
        }
        for(auto r : rightVec){
            if(r + 1 < distance) nodeVec.push_back(r + 1);
        }
        return nodeVec;
    }
    int countPairs(TreeNode* root, int distance) {
        int cnt = 0;
        dfs(root,distance,cnt);
        return cnt;
    }
};