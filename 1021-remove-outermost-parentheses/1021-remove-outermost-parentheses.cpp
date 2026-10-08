class Solution {
public:
    string removeOuterParentheses(string s) {
        // s     = "(()())(())"
        // depth =  1 2 1 2 1 0 1 2 1 0

        // s = "(()())(())(()(()))"
        // d =  1 2 2 2 2 1 1 2
        // ( -> ( : depth++, ( --> ) : depth--
        // ) --> ( : depth++ , ) --> ) : depth--

        // ((()()))
        // 1 2 3 2 3 2 1 0
        
        int n = s.size();
        if(n == 0) return s;
        vector<int> depth(n);
        depth[0] = 1;
        for(int i=1; i<n; i++){
            if(s[i] == '(') depth[i] = depth[i-1]+1;
            else if(s[i] == ')') depth[i] = depth[i-1]-1;
        }

        bool isOne = false, isZero = false;
        vector<bool> idxRemove(n,false);
        for(int i=0; i<n; i++){
            if(isOne && isZero){
                isOne = false;
                isZero = false;
            }
            if(depth[i] == 1 && isOne == false) {
                isOne = true;
                idxRemove[i] = true;
            }
            if(depth[i] == 0 && isZero == false) {
                isZero = true;
                idxRemove[i] = true;
            }
        }
        string ans;
        for(int i=0; i<n; i++){
            if(idxRemove[i] == false){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};