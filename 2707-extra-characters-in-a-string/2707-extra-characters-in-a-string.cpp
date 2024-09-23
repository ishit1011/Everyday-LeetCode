class Solution {
public:
    int solveMem(int i, string &s, unordered_map<string,int> &m, vector<int>& dp){
        if(i == s.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        string ans = "";
        int extraChar = 0, result = s.size(), totalChar;
        for(int idx = i; idx<s.size(); idx++){
            ans = ans + s[idx];
            if(m.find(ans) == m.end()){ // The character not found in dictionary
                extraChar = ans.size();
            }
            else{
                extraChar = 0;
            }
            int z = solveMem(idx+1,s,m,dp);
            totalChar = z + extraChar;
            result =  min(totalChar,result);
        }
        return dp[i] = result;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int> m;
        vector<int> dp(s.size(),-1);
        for(int i=0; i<dictionary.size(); i++){
            m[dictionary[i]] = 0;
        }
        return solveMem(0,s,m,dp);
    }
};