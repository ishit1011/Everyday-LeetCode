class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0, timeFlip = 0;

        vector<int> isFlip(n,0);
        for(int i=0; i<n; i++){
            if(i >= k){
                timeFlip -= isFlip[i-k];
            }
            if((nums[i] == 0 && timeFlip % 2 == 0) || (nums[i] == 1 && timeFlip % 2 == 1)){
                if(i+k > n){
                    return -1;
                }
                cnt++;
                timeFlip++;
                isFlip[i] = 1;
            }
        }
        return cnt;
    }
};