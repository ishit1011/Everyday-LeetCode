class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> stk;
        for(int i=0; i<n; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int n1 = stk.top(); stk.pop();
                int n2 = stk.top(); stk.pop();
                int n3 = 0;
                if(tokens[i] == "+") n3 = n2 + n1;
                else if(tokens[i] == "-") n3 = n2 - n1;
                else if(tokens[i] == "*") n3 = n2 * n1;
                else n3 = n2/n1;
                stk.push(n3);
            }
            else stk.push(stoi(tokens[i]));
        }
        return stk.top();
    }
};