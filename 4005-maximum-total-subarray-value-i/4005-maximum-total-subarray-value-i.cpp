class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int minVal = INT_MAX , maxVal = INT_MIN;
        for(int i=0; i<n; i++){
            minVal = min(minVal,nums[i]);
            maxVal = max(maxVal,nums[i]);
        }
        long long val = maxVal-minVal;
        long long totalSum = val * k; 
        return totalSum;
    }
};