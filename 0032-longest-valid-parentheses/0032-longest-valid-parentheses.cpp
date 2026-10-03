class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int n = s.size(), ans = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '(') stk.push(i);
            else{
                stk.pop();

                if(stk.empty()){
                    stk.push(i);
                }
                else{
                    int prev = stk.top();
                    ans = max(ans,i-prev);
                }
            }
        }

        return ans;
    }
};