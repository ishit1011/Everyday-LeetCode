class Solution {
public:
    bool isValid(string s) {
        if(s[0] == '}' || s[0] == ']' || s[0] == ')') return false;
        int n = s.size();
        stack<char> stk;
        stk.push(s[0]);
        for(int i=1; i<n; i++){
            char ele = s[i];
            if(stk.empty()){
                if(s[i] == '}' || s[i] == ']' || s[i] == ')') return false;
                else if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                    stk.push(s[i]);
                    continue;
                }
            }
            char f = stk.top();
            if(f == '('){
                if(ele == ')') stk.pop();
                else if(ele == ']' || ele == '}') return false;
                else if(ele == '(' || ele == '[' || ele == '{') stk.push(ele);
            }
            if(f == '{'){
                if(ele == '}') stk.pop();
                else if(ele == ']' || ele == ')') return false;
                else if(ele == '(' || ele == '[' || ele == '{') stk.push(ele);
            }
            if(f == '['){
                if(ele == ']') stk.pop();
                else if(ele == ')' || ele == '}') return false;
                else if(ele == '(' || ele == '[' || ele == '{') stk.push(ele);
            }
        }
        
        return stk.empty();
    }
};