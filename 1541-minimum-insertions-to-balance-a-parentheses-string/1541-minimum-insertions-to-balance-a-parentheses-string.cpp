class Solution {
public:
    int minInsertions(string s) {
        int open = 0, n = s.size(), ans = 0;
        int i = 0;

        while (i < n) {
            if (s[i] == '(') {
                open++;
                i++;
            } else {
                // Q1: is this a full "))"?
                if (i + 1 < n && s[i + 1] == ')') {
                    i += 2;          // consume both
                } else {
                    ans++;           // insert a missing ')'
                    i++;             // consume just this one
                }
                // Q2: does this closing unit have an opener?
                if (open > 0) open--;
                else ans++;          // insert a missing '('
            }
        }

        return ans + open * 2;       // each leftover '(' needs "))"
        
    }
};