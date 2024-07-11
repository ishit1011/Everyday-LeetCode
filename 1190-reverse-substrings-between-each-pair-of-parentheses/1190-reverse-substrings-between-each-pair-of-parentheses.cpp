class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        for(auto c : s){
            if(c == ')'){
                queue<string> q;
                while(!stk.empty() && stk.top() != "("){
                    q.push(stk.top());
                    stk.pop();
                }
                stk.pop();
                while(!q.empty()){
                    stk.push(q.front());
                    q.pop();
                }
            }
            else{
                stk.push(string(1,c));
            }
        }
        string ans;
        while(!stk.empty()){
            ans.push_back(stk.top()[0]);
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};