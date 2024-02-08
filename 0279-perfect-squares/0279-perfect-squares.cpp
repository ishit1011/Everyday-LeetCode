class Solution {
public:
    /*
        1. Recursion (Gives TLE)
    int solve(int n){
        if(n == 0){
            return 0;
        }
        int ans = INT_MAX;
        for(int i=1; i*i<=n; i++){
            ans = min(ans, solve(n-i*i)+1);
        }
        return ans;
    }*/
    /*
        2. Recursion + Memoization
    int solveMem(int n, vector<int>& dp){
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = INT_MAX;
        for(int i=1; i*i<=n; i++){
            ans = min(ans, solveMem(n-i*i,dp)+1);
        }
        dp[n] = ans;
        return dp[n];
    }*/
    //  3. Tabulation
    int solveTab(int n){
        vector<int> dp(n+1,0);
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            dp[i] = n;
            for(int j=1; j*j<=n; j++){
                if(i >= j*j)
                    dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        }
        return dp[n];
    }
    int numSquares(int n) {
        return solveTab(n);
    }
};