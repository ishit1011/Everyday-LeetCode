class Solution {
    int MOD = 1e9+7;
public:
    int Solve(int n, vector<int> &dp){
        if(n == 2) return n;
        if(dp[n] != -1) return dp[n];

        return dp[n] = (Solve(n-1, dp)*2%MOD + Solve(n-3, dp))%MOD;
    }
    int numTilings(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = dp[1] = 1;
        return Solve(n, dp);
    }
};