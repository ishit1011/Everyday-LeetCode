class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size(), m = words2.size();
        vector<int> maxFreq(26,0);
        for(int i=0; i<m; i++){
            vector<int> charFreq(26,0);
            for(char c : words2[i]){
                charFreq[c-'a']++;
            }
            for(int i=0; i<26; i++){
                if(maxFreq[i] < charFreq[i]){
                    maxFreq[i] = charFreq[i];
                }
            }
        }
        vector<string> ans;
        bool flag;
        for(int i=0; i<n; i++){
            flag = true;
            vector<int> charFreq(26,0);
            for(char c : words1[i]){
                charFreq[c-'a']++;
            }
            for(int i=0; i<26; i++){
                if(maxFreq[i] > charFreq[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};