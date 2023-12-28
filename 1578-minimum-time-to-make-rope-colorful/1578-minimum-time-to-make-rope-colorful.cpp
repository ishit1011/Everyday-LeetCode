class Solution {
public:
    int minCostRecursive(int i,string& colors,vector<int>& neededTime,char prevColor,int prevTime,vector<int>& dp){
        if(i < 0){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        if(colors[i] == prevColor){
            dp[i] = minCostRecursive(i-1,colors,neededTime,colors[i],max(neededTime[i], prevTime),dp)+min(neededTime[i], prevTime);
        }
        else{
            dp[i] = minCostRecursive(i-1,colors,neededTime,colors[i],neededTime[i],dp);
        }
        return dp[i];
    }
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        vector<int>dp(n,-1);
        return minCostRecursive(n-2, colors, neededTime, colors[n-1], neededTime[n-1],dp);
    }
};