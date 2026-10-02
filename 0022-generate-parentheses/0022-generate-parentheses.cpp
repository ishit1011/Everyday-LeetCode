class Solution {
public:
    vector<string> ans;
    void solve(int o, int c, string curr, int n){
        if(o == 0 && c == 0) {
            ans.push_back(curr);
            return;
        }
        if(o == c){
            // 1. add another '('
            solve(o-1,c,curr+'(',n);
        }
        else if(o < c){
            if(o == 0){
                // 1. add a ')'
                solve(o,c-1,curr+')',n);
            }
            else{
                // 1. add another '('
                solve(o-1,c,curr+'(',n);
                // 2. add a ')'
                solve(o,c-1,curr+')',n);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(n,n,curr,n);
        return ans;
    }
};