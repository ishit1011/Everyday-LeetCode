class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Subarray with sum ===> PREFIX SUM
        int n = nums.size();
        unordered_map<int,int> sumFreq;
        int sum = 0, cntSubarr = 0;
        sumFreq[0] = 1;
        for(int i=0; i<n; i++){
            sum += nums[i];
            int rem = sum - goal;
            if(sumFreq.find(rem) != sumFreq.end()){
                cntSubarr += sumFreq[rem];
            }
            sumFreq[sum]++;
        }
        return cntSubarr;
    }
};