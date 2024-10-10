class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // Example : [6,0,8,2,1,5]
        int n = nums.size();
        stack<int> stk;

        // 1. Monotonically Decreasing Stack
        // stk : [0,1] (Index stored)
        for(int i=0; i<n; i++){
            if(stk.empty() || nums[stk.top()] >= nums[i]){
                stk.push(i);
            }
        }

        // 2. Check for maxWidth from behind the array
        int maxWidth = 0;
        for(int j=n-1; j>=0; j--){
            while(!stk.empty() && nums[stk.top()] <= nums[j]){
                maxWidth = max(maxWidth,j-stk.top());
                stk.pop();
            }
        }
        return maxWidth;
    }
};