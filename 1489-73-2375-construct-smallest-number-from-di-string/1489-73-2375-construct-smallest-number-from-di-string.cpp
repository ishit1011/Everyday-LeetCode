class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        stack<int> stk;
        string ans = "";
        for(int i=0; i<=n; i++){
            stk.push(i+1);
            if(i == n || pattern[i] == 'I'){
                while(!stk.empty()){
                    ans += to_string(stk.top());
                    stk.pop();
                }
            }
        }
        return ans;
    }
};