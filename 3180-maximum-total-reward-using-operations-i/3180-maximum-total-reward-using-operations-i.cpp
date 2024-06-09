class Solution {
public:
    int solve(vector<int>& rewardValues, int i, int currReward, vector<vector<int>> &dp){
        if(i > rewardValues.size()-1){
            return currReward;
        }
        if(dp[i][currReward] != -1){
            return dp[i][currReward];
        }
        int taken = 0;
        if(rewardValues[i] > currReward){
            taken = solve(rewardValues,i+1,currReward + rewardValues[i],dp);
        }
        int notTaken = solve(rewardValues,i+1,currReward,dp);
        return dp[i][currReward] = max(taken,notTaken);
    }
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        int ans = 0;
        sort(rewardValues.begin(),rewardValues.end());
        vector<vector<int>> dp(n, vector<int>(5000, -1));
        ans = solve(rewardValues,0,0,dp);
        return ans;
    }
};