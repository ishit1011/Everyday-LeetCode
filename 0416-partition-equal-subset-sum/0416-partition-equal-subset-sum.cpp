class Solution {
public:
    bool solve(vector<int>& nums, int i, int maxSum, vector<vector<int>> &dp){
        if(i == nums.size()) return false;
        if(maxSum < 0) return false;
        if(maxSum == 0) return true;
        if(dp[i][maxSum] != -1) return false;

        bool take = solve(nums,i+1,maxSum-nums[i],dp);
        bool notTake = solve(nums,i+1,maxSum,dp);
        return dp[i][maxSum] =  take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int arrSum = 0, n = nums.size();
        for(int i=0; i<n; i++){
            arrSum += nums[i];
        }
        if(arrSum % 2 != 0) return false;
        int half = arrSum/2;
        vector<vector<int>> dp(n+1,vector<int>(half+1,-1));
        return solve(nums,0,half,dp);
    }
};