class Solution {
public:
    long long MOD = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        int len = 0;

        vector<long long> alpha(26,0);
        for(int i=0; i<n; i++){
            alpha[s[i]-'a']++;
        }
        while(t--){
            int zCnt = alpha[25];
            for (int i = 25; i > 0; i--) {
                alpha[i] = alpha[i - 1] % MOD;
            }
            alpha[0] = 0;
            if (zCnt > 0) {
                alpha[0] = (alpha[0] + zCnt) % MOD;
                alpha[1] = (alpha[1] + zCnt) % MOD;
            }
        }
        for(int i=0; i<26; i++){
            len = (len + alpha[i]) % MOD;
        }
        return len;
    }
};