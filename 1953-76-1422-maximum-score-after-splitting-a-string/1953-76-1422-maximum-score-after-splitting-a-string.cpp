class Solution {
public:
    int maxScore(string s) {
        int ans = INT_MIN;
        int totalOnes = 0, leftZeros = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1') totalOnes++;
        }
        for(int i=0; i<s.size()-1; i++){
            if(s[i] == '0'){
                leftZeros++;
            }
            else{
                totalOnes--;
            }
            ans = max(ans,leftZeros+totalOnes);
        }
        return ans;
    }
};