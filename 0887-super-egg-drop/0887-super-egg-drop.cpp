class Solution {
public:
    int solve(int eggsLeft, int floorsLeft, vector<vector<int>>& dp){
        if(eggsLeft <= 1 || floorsLeft <= 1) return floorsLeft;
        if(dp[eggsLeft][floorsLeft] != -1){
            return dp[eggsLeft][floorsLeft];
        }
        int l = 0, h = floorsLeft;
        int minSteps = INT_MAX;
        while(l <= h){
            int mid = (l+h)/2;
            int breakEgg = solve(eggsLeft-1, mid-1, dp);
            int notBreakEgg = solve(eggsLeft, floorsLeft-mid, dp);
            int currSteps = 1 + max(breakEgg, notBreakEgg);
            minSteps = min(minSteps, currSteps);
            if(breakEgg > notBreakEgg){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return dp[eggsLeft][floorsLeft] = minSteps;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1)); 
        return solve(k,n,dp);
    }
};