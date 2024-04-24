class Solution {
public: 
    // int ans;
    // int solve(int n){
    //     if(n <= 1){
    //         return n;
    //     }
    //     else if(n == 2){
    //         return 1;
    //     }
    //     else{
    //         ans = solve(n-1) + solve(n-2) + solve(n-3);
    //     }
    //     return ans;
    // }
    int solveMem(int n, vector<int>& dp){
        if(n <= 1){
            return n;
        }
        if(n == 2){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = solveMem(n-1,dp) + solveMem(n-2,dp) + solveMem(n-3,dp);
        return dp[n];
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return solveMem(n,dp);
    }
};