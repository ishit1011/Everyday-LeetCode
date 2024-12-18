class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // Monotonic Inc stack from 0 --> n-1
        int n = prices.size();
        stack<int> stk;
        vector<int> ans = prices;
        for(int i=0; i<n; i++){
            while(!stk.empty() && prices[stk.top()] >= prices[i]){
                ans[stk.top()] -= prices[i];
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};