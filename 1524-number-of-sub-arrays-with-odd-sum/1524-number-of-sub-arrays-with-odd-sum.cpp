class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size(), prefixSum = 0;

        int oddPrefixSumSubarr = 0, evenPrefixSumSubarr = 1, count = 0;
        long long MOD = 1000000007;

        for(int i=0; i<n; i++){
            prefixSum += arr[i];
            if(prefixSum % 2 == 0){
                count += oddPrefixSumSubarr; // odd sub arr can combine with these
                evenPrefixSumSubarr++;
            }
            else{
                count += evenPrefixSumSubarr; // even sub arr can combine with these
                oddPrefixSumSubarr++;
            }

            count %= MOD;
        }
        return count;
    }
};