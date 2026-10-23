class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> unsort;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] != i) unsort.push_back(nums[i]);
        }

        if(unsort.size() == 0) return 0;
        int ans = unsort[0];
        for(int i=1; i<unsort.size(); i++){
            ans = ans & unsort[i];
        }
        return ans;
    }
};