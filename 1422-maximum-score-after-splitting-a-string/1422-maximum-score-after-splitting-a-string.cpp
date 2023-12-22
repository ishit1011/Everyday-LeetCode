class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        int ones = count(s.begin(),s.end(),'1');
        int zeros = 0;
        for(int i=0; i<s.size()-1; i++){
            if(s[i] == '1'){
                ones--;
            }
            else{
                zeros++;
            }
            ans = max(ans,zeros+ones);
        }
        return ans;
    }
};