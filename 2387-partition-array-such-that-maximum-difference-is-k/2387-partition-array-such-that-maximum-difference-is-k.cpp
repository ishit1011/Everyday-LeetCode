class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int partitionCnt = 1, firstIdx = 0;
        for(int i=1; i<n; i++){
            if(nums[i] - nums[firstIdx] > k){
                partitionCnt++;
                firstIdx = i;
            }
        }
        return partitionCnt;
    }
};