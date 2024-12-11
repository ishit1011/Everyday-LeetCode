class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int r = 0, maxBeauty = 0;
        for(int i=0; i<n; i++){
            while(r < n && nums[r]-nums[i] <= 2*k){
                r++;
            }
            maxBeauty = max(maxBeauty,r-i);
        }
        return maxBeauty;
    }
};