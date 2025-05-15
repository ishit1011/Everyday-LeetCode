class Solution {
public:
    vector<string> solve(vector<string>& words, vector<int>& groups, vector<string>& ans, int i){
        for(int i=0; i<words.size(); i++){
            if(i == 0 || (i > 0 && groups[i] != groups[i-1])){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        return solve(words,groups,ans,0);
    }
};