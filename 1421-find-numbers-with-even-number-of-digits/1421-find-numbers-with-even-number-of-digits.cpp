class Solution {
public:
    int cntDigits(int num){
        int cnt = 0;
        while(num > 0){
            cnt++;
            num /= 10;
        }
        return cnt;
    }
    int findNumbers(vector<int>& nums) {
        int total = 0;
        for(int i=0; i<nums.size(); i++){
            if(cntDigits(nums[i]) % 2 == 0){
                total++;
            }
        }
        return total;
    }
};