class Solution {
public:
    int solve(string &s, int i, int j, vector<vector<int>>& dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int op1 = 0, op2 = 0;
        if(s[i] == s[j]){
            if(i != j){
                op1 = 2 + solve(s,i+1,j-1,dp);
            }
            else{
                op1 = 1 + solve(s,i+1,j-1,dp);
            }
        }
        else{
            op2 = max(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
        }
        return dp[i][j] = max(op1,op2);
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(s,0,n-1,dp);
    }
};