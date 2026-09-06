class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxLeft(n,nums[0]), minRight(n,nums[n-1]);
        for(int i=1; i<n; i++){
            maxLeft[i] = max(nums[i],maxLeft[i-1]);
        }
        for(int i=n-2; i>=0; i--){
            minRight[i] = min(nums[i],minRight[i+1]);
        }

        for(int i=0; i<n; i++){
            int score = maxLeft[i]-minRight[i];
            if(score <= k){
                return i;
            }
        }
        return -1;
    }
};