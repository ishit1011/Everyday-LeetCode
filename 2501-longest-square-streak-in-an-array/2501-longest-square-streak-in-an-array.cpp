class Solution {
public:
    /*          DP [Memory Limit Exceeded]
    int solve(vector<int>& nums, int prev, int curr, vector<vector<int>> &dp){
        if(curr == nums.size()){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev];
        }
        int take = 0, notTake = 0;
        if(prev == -1 || (nums[curr]/nums[prev] == nums[prev])){
            take = 1 + solve(nums,curr,curr+1,dp);
            notTake = solve(nums,prev,curr+1,dp);
        }
        else{
            notTake = solve(nums,prev,curr+1,dp);
        }
        return dp[curr][prev+1] = max(take,notTake);
    }*/
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> valLenMp;

        for(int x : nums){
            int root = sqrt(x);
            if(root*root == x && valLenMp.find(root) != valLenMp.end()){
                valLenMp[x] = valLenMp[root] + 1;
            }
            else{
                valLenMp[x] = 1;
            }
        }
        int maxLen = 0;
        for(auto [p,q] : valLenMp){
            maxLen = max(maxLen,q);
        }
        return maxLen < 2 ? -1 : maxLen;
    }
};