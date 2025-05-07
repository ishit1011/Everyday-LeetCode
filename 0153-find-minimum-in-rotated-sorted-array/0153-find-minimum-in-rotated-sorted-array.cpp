class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int ans = INT_MAX;

        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] <= ans){
                ans = nums[mid];
            }
            if(nums[r] > ans){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};