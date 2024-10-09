class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        for(char ch : s){
            if(stk.empty() || stk.top() == ')' || ch == '('){
                stk.push(ch);
            }
            if(stk.top() == '(' && ch == ')'){
                stk.pop();
                continue;
            }
        }
        return stk.size();
    }
};