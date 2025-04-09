class Solution {
public:

    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        vector<int> greaterEle;
        for(int i=n-1; i>=0; i--){
            stk.push(nums[i]);
        }
        for(int i=n-1; i>=0; i--){
            if(stk.empty()){
                greaterEle.push_back(-1);
            }
            else{
                if(stk.top() > nums[i]){
                    greaterEle.push_back(stk.top());
                }
                else{
                    while(!stk.empty() && stk.top() <= nums[i]){
                        stk.pop();
                    }
                    if(stk.empty()){
                        greaterEle.push_back(-1);
                    }
                    else{
                        greaterEle.push_back(stk.top());
                    }
                }
            }
            stk.push(nums[i]);
        }
        reverse(greaterEle.begin(),greaterEle.end());
        return greaterEle;
    }
};