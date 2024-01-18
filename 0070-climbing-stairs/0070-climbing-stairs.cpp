class Solution {
public:
    /*          1. Recursion 
    int solve(int n){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        int ans = 0;
        ans = ans + solve(n-1) + solve(n-2);
        return ans;
    }*/
    /*          2. Recursion + Memoization
                    n : n ----> 0 (Top-Down Approach)
    int solveMem(int n, vector<int>& dp){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = 0;
        ans = ans + solveMem(n-1,dp) + solveMem(n-2,dp);
        return dp[n] = ans;
    }*/
    int solveTab(int n){
        vector<int> dp(n+1,0);
        
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        // return solve(n);
        // return solveMem(n,dp);
        if(n <= 2){
            return n;
        }
        else{
            return solveTab(n);
        }
    }
};