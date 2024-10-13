class Solution {
public:
    int solve(vector<int>& nums, int target, int i, int sum){
        if(i == nums.size()){
            return (sum == target);
        }
        int sub = solve(nums,target,i+1,sum-(2*nums[i]));
        int add = solve(nums,target,i+1,sum);
        return sub+add;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        return solve(nums,target,0,sum);
    }
};