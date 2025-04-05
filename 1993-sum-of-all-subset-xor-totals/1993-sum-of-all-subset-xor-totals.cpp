class Solution {
public:
    int solve(vector<int>& nums, int i, int xorSum){
        if(i == nums.size()){
            return xorSum;
        }
        int include = solve(nums,i+1,xorSum^nums[i]);
        int exclude = solve(nums,i+1,xorSum);
        return include + exclude;
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(nums,0,0);
    }
};