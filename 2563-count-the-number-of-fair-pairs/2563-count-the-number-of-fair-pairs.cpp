class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        long long cnt = 0;
        for(int i=0; i<n; i++){
            auto u = upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i]);
            auto l = lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]);
            cnt += (u-l);
        }
        return cnt;
    }
};