class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = -1;
        for(int i=0; i<n-1; i++){
            maxDiff = max(maxDiff,abs(nums[i]-nums[i+1]));
        }
        maxDiff = max(maxDiff,abs(nums[n-1]-nums[0]));
        return maxDiff;
    }
};