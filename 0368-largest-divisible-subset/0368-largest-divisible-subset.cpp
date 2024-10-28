class Solution {
public:
    vector<int> temp;
    void solve(vector<int>& nums, int curr, vector<int> &ans, vector<int> &dp){
        if(curr >= nums.size()){
            if(ans.size() > temp.size()){
                temp = ans;
            }
            return;
        }
        if((ans.empty() || nums[curr] % ans.back() == 0) && dp[curr] < (int)ans.size()){
            dp[curr] = ans.size();
            ans.push_back(nums[curr]);
            solve(nums,curr+1,ans,dp);
            ans.pop_back();
        }
        solve(nums,curr+1,ans,dp);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int n = nums.size();
        vector<int> dp(n+1,-1);
        solve(nums,0,ans,dp);
        return temp;
    }
};