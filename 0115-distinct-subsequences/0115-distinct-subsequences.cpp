class Solution {
public:
    int solve(string &s, string &t, int i, int j, int n, int m, vector<vector<int>> &dp){
        if(j == m) return 1;
        if(i == n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int take = 0;
        if(s[i] == t[j]){
            take = solve(s,t,i+1,j+1,n,m,dp);
        }
        int notTake = solve(s,t,i+1,j,n,m,dp);

        return dp[i][j] = take + notTake;
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = solve(s,t,0,0,n,m,dp);
        return ans;
    }
};