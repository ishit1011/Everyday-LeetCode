class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int cnt = 0;
        int l = 0, r = 2;
        while(r < nums.size()){
            int mid = (l+r)/2;
            int sum = nums[l]+nums[r];
            float half = nums[mid]/2.0;
            if(sum == half){
                cnt++;
            }
            l++;
            r++;
        }
        return cnt;
    }
};