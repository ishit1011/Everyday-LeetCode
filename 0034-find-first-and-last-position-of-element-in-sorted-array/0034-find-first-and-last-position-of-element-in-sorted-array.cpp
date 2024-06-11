class Solution {
public:
    vector<int> ans;
    int b(vector<int>& nums, int target, int low, int high, bool searchingLeft){
        int idx = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] > target){
                high = mid-1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                idx = mid;
                if(searchingLeft == true){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
        }
        return idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = b(nums,target,0,n-1,true);
        int right = b(nums,target,0,n-1,false);

        ans.push_back(left);
        ans.push_back(right);
        return ans;
    }
};