class Solution {
public:
    int MOD = 1000000007;
    int solve(int n, int x, int i, vector<vector<int>> &dp){
        if(n == 0) return 1;
        int num = pow(i,x);
        if(n-num < 0) return 0;
        if(dp[n][i] != -1) return dp[n][i];

        int takeWays = solve(n-num,x,i+1,dp);
        int notTakeWays = solve(n,x,i+1,dp);

        return dp[n][i] = (takeWays + notTakeWays) % MOD;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(n,x,1,dp);
    }
};