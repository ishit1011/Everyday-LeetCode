class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int smallest = nums[0];
        if(smallest > 0){
            return 0;
        }
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1]-nums[i] > 1){
                return nums[i]+1;
            }
        }
        return nums[n-1]+1;
    }
};