class Solution {
public:
    int checkMinIdx(vector<int>& nums, int currIdx, int minReq){
        sort(nums.begin(),nums.end());
        for(int i=currIdx+1; i<nums.size(); i++){
            if(nums[i] >= minReq){
                return i;
            }
        }
        return -1;
    }
    int checkMaxIdx(vector<int>& nums, int currIdx, int maxReq){
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1; i>currIdx; i--){
            if(nums[i] <= maxReq){
                return i;
            }
        }
        return -1;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long count = 0;

        for(int i=0; i<n; i++){
            int minVal = lower-nums[i], maxVal = upper-nums[i];
            auto idxMin = lower_bound(nums.begin()+i+1,nums.end(),minVal);
            auto idxMax = upper_bound(nums.begin()+i+1,nums.end(),maxVal);
            
            count += idxMax-idxMin;
        }
        return count;
    }
};