class Solution {
public:
    int solve(int amount, vector<int>& coins, int i, int n, vector<vector<int>>& dp){
        if(i == n-1){
            return (amount%coins[i] == 0);
        }
        if(dp[amount][i] != -1){
            return dp[amount][i]; 
        }
        int t = 0, nT = 0;
        if(amount >= coins[i]){  
            t = solve(amount-coins[i],coins,i,n,dp);
        }
        nT = solve(amount,coins,i+1,n,dp);
        return dp[amount][i] = t+nT;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n,-1));
        return solve(amount,coins,0,n,dp);
    }
};