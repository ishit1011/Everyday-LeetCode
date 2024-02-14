class Solution {
public:
    /*      ALGORITHM
        1. Initialize n to the size of nums.Initialze ans array of size n.
        2. Initialize two integers posIndex and negIndex with 0 and 1 respectively.
        3. Traverse nums from the start. Note that 0 won't be in the array according to the constraints.
            i. If the current integer is positive, set ans[posIndex] equal to it. Increment posIndex by 2.
            ii. If the current integer is negative, set ans[negIndex] equal to it. Increment negIndex by 2.
        4. Once nums is fully traversed, return ans.
    */
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int positiveIdx = 0, negativeIdx = 1;
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                ans[positiveIdx] = nums[i];
                positiveIdx += 2;
            }
            else{
                ans[negativeIdx] = nums[i];
                negativeIdx += 2;
            }
        }
        return ans;
    }
};