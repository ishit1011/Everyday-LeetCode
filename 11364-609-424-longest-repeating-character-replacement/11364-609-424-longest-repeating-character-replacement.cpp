class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, maxLen = -1, maxFreq = 0;
        vector<int> freq(26,0);
        for(int r=0; r<n; r++){
            freq[s[r]-'A']++;
            maxFreq = max(maxFreq,freq[s[r]-'A']);
            // if non similar elements are > allowed flips
            if((r-l+1) - maxFreq > k){
                freq[s[l]-'A']--;
                l++;
            }
            else{
                maxLen = max(maxLen,r-l+1);
            }
        }
        return maxLen;
    }
};