class Solution {
public:

    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        stack<int> stk;

        for(int i=n-1; i>=0; i--){
            stk.push(nums[i]);
        }

        for(int i=n-1; i>=0; i--){
            if(stk.empty()){
                ans.push_back(-1);
            }
            else{
                // 1. Monotonic Decreasing stack
                if(stk.top() > nums[i]){
                    ans.push_back(stk.top());
                }
                else{
                    while(!stk.empty() && stk.top() <= nums[i]){
                        stk.pop();
                    }
                    if(stk.empty()){
                        ans.push_back(-1);
                    }
                    else{
                        ans.push_back(stk.top());
                    }
                }
            }
            stk.push(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};