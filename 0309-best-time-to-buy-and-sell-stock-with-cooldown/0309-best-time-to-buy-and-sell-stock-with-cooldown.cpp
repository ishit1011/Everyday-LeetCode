class Solution {
public:
    int solve(vector<int>& prices, int i, int buy, int n, vector<vector<int>> &dp){
        if(i >= n){
            return 0;
        }
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }
        int profit = 0;
        if(buy == 1){
            int bought = -prices[i] + solve(prices,i+1,0,n,dp); 
            int notB = solve(prices,i+1,1,n,dp);
            profit = max(bought,notB);
        }
        else{
            int sold = prices[i] + solve(prices,i+2,1,n,dp);
            int notS = solve(prices,i+1,0,n,dp);
            profit = max(sold,notS);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(prices,0,1,n,dp);
    }
};