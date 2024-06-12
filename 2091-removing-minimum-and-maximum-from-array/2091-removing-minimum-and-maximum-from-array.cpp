class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx, maxIdx;
        int mx = INT_MIN, mn = INT_MAX;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] > mx){
                mx = nums[i];
                maxIdx = i;
            }
            if(nums[i] < mn){
                mn = nums[i];
                minIdx = i;
            }
        }
        int left = max(minIdx,maxIdx) + 1;
        int right = n - min(minIdx,maxIdx);
        
        return min(min(left,right) , min(minIdx,maxIdx) + 1 + n - max(minIdx,maxIdx));
    }
};