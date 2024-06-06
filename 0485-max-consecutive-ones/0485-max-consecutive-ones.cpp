class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int windowSize = 0, n = nums.size();
        int j = 0;
        for(int i=0; i<n; i ++){
            j = i+1;
            if(nums[i] == 1){
                windowSize = max(windowSize,1);
                while(j < n && nums[j] == 1){
                    j++;
                }
                windowSize = max(windowSize,j-i);
            }
        }
        return windowSize;
    }
};