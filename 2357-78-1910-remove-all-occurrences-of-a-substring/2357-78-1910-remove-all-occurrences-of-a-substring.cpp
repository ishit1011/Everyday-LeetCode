class Solution {
public:
    bool charCheck(string &part, stack<char> &stk){
        int len = part.size();
        stack<char> temp = stk;

        for(int i=len-1; i>=0; i--){
            if(temp.top() != part[i]){
                return false;
            }
            temp.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part) {
        int len = part.size(), n = s.size();
        stack<char> stk;

        for(int i=0; i<n; i++){
            stk.push(s[i]);
            if(stk.size() >= len && charCheck(part,stk)){
                for(int i=0; i<len; i++){
                    stk.pop();
                }
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