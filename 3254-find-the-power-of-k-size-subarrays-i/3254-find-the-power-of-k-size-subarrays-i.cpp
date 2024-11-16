class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = k-1;
        vector<int> ans;
        while(r < n){
            bool flag = true;
            for(int i=l; i<r; i++){
                if(nums[i] >= nums[i+1] || nums[i+1]-nums[i] > 1){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans.push_back(nums[r]);
            }
            else{
                ans.push_back(-1);
            }
            l++;
            r++;
        }
        return ans;
    }
};