class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> modulusWithIdx;
        int prefixSum = 0, maxLen = 0;
        for(int i=0; i<n; i++){
            prefixSum += nums[i];

            if(modulusWithIdx.find(prefixSum % k) != modulusWithIdx.end()){
                int idx = modulusWithIdx[(prefixSum % k)];
                maxLen = max(maxLen,i-idx);
            }
            if((prefixSum % k) == 0){
                maxLen = max(maxLen,i+1);
            }
            if(modulusWithIdx.find(prefixSum % k) == modulusWithIdx.end()){
                modulusWithIdx[(prefixSum % k)] = i;
            }

            if(maxLen >= 2){
                return true;
            }
        }
        return false;
    }
};