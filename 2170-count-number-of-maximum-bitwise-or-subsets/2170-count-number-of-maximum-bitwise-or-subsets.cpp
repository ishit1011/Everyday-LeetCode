class Solution {
    int solve(vector<int>& nums, int tar, int i, int cur){
        if(i == nums.size()){
            return (cur == tar); 
        }
        int take = solve(nums,tar,i+1,cur | nums[i]);
        int notTake = solve(nums,tar,i+1,cur);
        return take + notTake;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOR = 0;
        for(int i=0; i<n; i++){
            maxOR = maxOR | nums[i];
        }
        return solve(nums,maxOR,0,0);
    }
};