class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zeros = 0, maxLength = 0;
        for(int right = 0; right < nums.size(); right++) {
            if(nums[right] == 0) zeros++;
            
            // If more than 1 zero, shrink window
            while(zeros > 1) {
                if(nums[left] == 0) zeros--;
                left++;
            }
            
            // window size minus 1 (delete one element)
            maxLength = max(maxLength, right - left);
        }
        return maxLength;
    }
};