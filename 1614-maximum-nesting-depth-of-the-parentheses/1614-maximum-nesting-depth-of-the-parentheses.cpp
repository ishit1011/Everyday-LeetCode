class Solution {
public:
    int maxDepth(string s) {
        int n = s.size(), maxCnt = 0, cnt = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                cnt++;
            }
            if(s[i] == ')'){
                cnt--;
            }
            maxCnt = max(cnt,maxCnt);
        }
        return maxCnt;
    }
};