class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> remWithFreq;
        int prefixSum = 0, count = 0;
        remWithFreq[0] = 1;

        for(int i=0; i<n; i++){
            prefixSum += nums[i];
            int rem = prefixSum % k;

            if(rem < 0){
                rem += k;
            }

            count += remWithFreq[rem];
            remWithFreq[rem]++;
        }
        return count;
    }
};