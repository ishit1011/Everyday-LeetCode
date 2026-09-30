class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth = 0;
        vector<int> ans;
        int n = seq.size();
        for(int i=0; i<n; i++){
            if(seq[i] == '('){
                ans.push_back(depth % 2);
                depth++;
            }
            else{
                depth--;
                ans.push_back(depth % 2);
            }
        }
        return ans;
    }
};