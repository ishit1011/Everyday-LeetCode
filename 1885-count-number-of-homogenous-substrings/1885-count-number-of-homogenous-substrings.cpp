class Solution {
public:
    int countHomogenous(string s) {
        // 1. Initialize total no. of substrings as length of string
        long sum = s.length();
        const int MOD = 1000000007;
    
        int l = 0, h = 1;
        while(h < s.size()){
            // 3. When s[low] != s[high] -->  re-shift the sliding window
            if(s[h] != s[l]){
                l=h;
            }
            else{
                // 2. When s[low] = s[high] --> sum is increased by no.
                //                              of elements b/w "l" & "h"
                sum += (h-l);
            }
            h++;
        }
        return sum % MOD;
        // As written in the question
    }
};