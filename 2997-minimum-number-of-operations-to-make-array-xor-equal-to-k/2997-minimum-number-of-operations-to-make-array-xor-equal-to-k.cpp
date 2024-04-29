class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorRes = nums[0];
        for(int i=1; i<nums.size(); i++){
            xorRes ^= nums[i];
        }
        int temp = xorRes ^ k;
        int totalChanges = 0;
        while(temp > 0){
            if(temp & 1 == 1){  // If the current bit is set(i.e == 1) --> change occured
                totalChanges++;
            }
            temp >>= 1;
        }
        return totalChanges;
    }
};