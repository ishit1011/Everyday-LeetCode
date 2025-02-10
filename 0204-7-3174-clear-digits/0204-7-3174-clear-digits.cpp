class Solution {
public:
    string clearDigits(string s) {
        stack<char> stk;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                stk.push(s[i]);
            }
            else{
                stk.pop();
            }
        }
        string ans = "";
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};