class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l < r){
            int mid = (l+r)/2;
            if(nums[mid] < target){
                l = mid+1;
            }
            else if(nums[mid] > target){
                r = mid-1;
            }
            else{
                return mid;
            }
        }
        return target > nums[l] ? l+1 : l;
    }
};