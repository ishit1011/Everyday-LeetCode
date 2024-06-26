class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int i = 0, cnt = 0;
        if(n<=1){
            return 0;
        }
        while(i<n){
            if(nums[i] + i >= n-1) return cnt + 1;
            int maxNum = 0, idx;
            for(int j=nums[i]+i; j>i; j--){
                if(maxNum < nums[j] + j){
                    maxNum = nums[j] + j;
                    idx = j;
                }
            }
            i = idx;
            cnt++;
        }
        return cnt;
    }
};