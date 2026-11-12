class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), len = 1, chk = -1;
        int maxLen = len;

        for(int i=1; i<n; i++){
            int curr = nums[i], prev = nums[i-1];
            if(curr > prev){
                if(chk == -1){
                    len++;
                    chk = 1;
                }
                else if(chk == 0){
                    len = 2;
                    chk = 1;
                }
                else if(chk == 1) len++;
            }
            else if(curr < prev){
                if(chk == -1){
                    len++;
                    chk = 0;
                }
                else if(chk == 1){
                    len = 2;
                    chk = 0;
                }
                else if(chk == 0) len++;
            }
            else{
                len = 1;
                chk = -1;
            }

            maxLen = max(maxLen,len);
        }
        return maxLen;
    }
};