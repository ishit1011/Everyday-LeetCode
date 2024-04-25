class Solution {
public:
    // int solve(string s, int k, int i, char prevChar){
    //     int select = 0, skip = 0;
    //     if(i >= s.size()){
    //         return 0;
    //     }
    //     if(prevChar == '`' || abs(s[i]-prevChar) <= k){
    //         select = 1 + solve(s,k,i+1,s[i]);
    //     }
    //     skip = solve(s,k,i+1,prevChar);

    //     return max(select,skip);
    // }
    int solveMem(string& s, int k, int i, char prevChar, vector<vector<int>> &dp){
        if(i == s.size())return 0;
        if(prevChar != '{' && dp[i][prevChar-'a'] != -1){
            return dp[i][prevChar-'a'];
        }

        int skip = solveMem(s,k,i+1,prevChar,dp);
        int select = 0;
        if(prevChar == '{' || abs(s[i]-prevChar) <= k){
            select = 1 + solveMem(s,k,i+1,s[i],dp);
        }
        return dp[i][prevChar-'a'] = max(select,skip);
    }
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(27,-1));
        return solveMem(s,k,0,'{',dp);
    }
};