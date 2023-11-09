class Solution {
public:
    int countHomogenous(string s) {
        long sum = s.length();
        const int MOD = 1000000007;
        int l = 0, h = 1;
        while(h < s.size()){
            if(s[h] != s[l]){
                l=h;
            }
            else{
                sum += (h-l);
            }
            h++;
        }
        return sum % MOD;
    }
};