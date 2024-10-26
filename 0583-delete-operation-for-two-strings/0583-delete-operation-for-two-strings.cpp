class Solution {
public:
    int solve(string w1, string w2, int i, int j, vector<vector<int>> &dp){
        if(i >= w1.size()){
            return dp[i][j] = w2.size()-j;
        }
        if(j >= w2.size()){
            return dp[i][j] = w1.size()-i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(w1[i] == w2[j]){
            return dp[i][j] = solve(w1,w2,i+1,j+1,dp);
        }
        return dp[i][j] =  1 + min(solve(w1,w2,i,j+1,dp), solve(w1,w2,i+1,j,dp));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(word1,word2,0,0,dp);
    }
};