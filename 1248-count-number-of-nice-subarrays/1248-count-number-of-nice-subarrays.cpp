class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        // 1. Convert all odd num = 1 & even num = 0
        for(int i=0; i<n; i++){
            nums[i] = nums[i] % 2;
        }

        // 2. Problem becomes no. of subarrays with sum 'k'
        map<int,int> sumFreq;
        int count = 0, sum = 0;

        for(int i=0; i<n; i++){
            sum += nums[i];
            sumFreq[sum] ++;
            if(sum == k){
                count++;
            }
            int rem = sum - k;
            if(sumFreq.find(rem) != sumFreq.end()){
                count += sumFreq[rem];
            }
        } 
        return count;
    }
};