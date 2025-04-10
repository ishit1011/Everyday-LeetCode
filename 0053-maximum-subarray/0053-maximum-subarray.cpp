class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        // Kadanes algorithm
        int maxSumHere = -10000, maxSubarraySum = -10000;
        for(int i=0; i<n; i++){
            int curr = maxSumHere+nums[i];
            maxSumHere = max(curr,nums[i]);
            maxSubarraySum = max(maxSumHere,maxSubarraySum);
        }
        return maxSubarraySum;
    }
};