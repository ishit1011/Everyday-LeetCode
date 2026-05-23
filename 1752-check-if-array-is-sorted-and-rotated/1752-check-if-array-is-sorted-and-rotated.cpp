class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), p = 0, pIdx = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]) {
                pIdx = i+1;
                p++;
            }
            if(p == 2) return false;
        }

        // when pivot = 1 --> still not sorted
        if(p == 1 && nums[0] < nums[n-1]) return false;

        return true;
    }
};