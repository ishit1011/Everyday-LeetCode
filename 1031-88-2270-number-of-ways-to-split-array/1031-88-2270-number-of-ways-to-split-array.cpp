class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n,0);
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++){
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }
        int cnt = 0;
        long long finalSum = prefixSum[n-1];
        for(int i=0; i<n-1; i++){
            if(prefixSum[i] >= finalSum-prefixSum[i]){
                cnt++;
            }
        }
        return cnt;
    }
};