class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int firstIdx = -1, lastIdx = -1, cntDiff = 0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]){
                if(cntDiff == 0){
                    firstIdx = i;
                    lastIdx = i;
                }
                if(cntDiff == 1){
                    lastIdx = i;
                }
                if(cntDiff > 1){
                    return false;
                }
                cntDiff++;
            }
        }
        if(cntDiff == 0) return true;
        return ((s1[firstIdx] == s2[lastIdx]) && (s1[lastIdx] == s2[firstIdx]));
    }
};