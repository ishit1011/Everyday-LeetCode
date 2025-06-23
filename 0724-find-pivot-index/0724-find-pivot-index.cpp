class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        /* Brute force :
            - at every index you traverse left of the index elements & right of thr index elements 
        */ 
        // Optimised : use prefix sum
        int n = nums.size();
        vector<int> prefixSum;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            prefixSum.push_back(sum);
        }
        int pivot = -1;
        for(int i=0; i<n; i++){
            if(i == 0){
                int sumL = 0;
                int sumR = prefixSum[n-1]-prefixSum[i];
                if(sumL == sumR){
                    pivot = i;
                    break;
                }
            }
            else if(i == n-1){
                int sumL = prefixSum[i-1];
                int sumR = 0;
                if(sumL == sumR){
                    pivot = i;
                    break;
                }
            }
            else{
                int sumL = prefixSum[i-1];
                int sumR = prefixSum[n-1]-prefixSum[i];
                if(sumL == sumR){
                    pivot = i;
                    break;
                }
            }
        }
        return pivot;
    }
};