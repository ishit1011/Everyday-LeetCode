class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> sumFreq;
        int sum = 0, count = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(sum == k){
                count++;
            }
            int rem = sum - k;
            if(sumFreq.find(rem) != sumFreq.end()){
                count += sumFreq[rem];
            }
            sumFreq[sum]++;
        }   
        return count;
    }
};