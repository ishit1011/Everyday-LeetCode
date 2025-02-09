class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0 || s.size() == 1) return s.size();
        int n = s.size();
        int l = 0, r = 1;
        if(s.size() == 2){
            if(s[l] != s[r]) return 2;
            else return 1;
        }
        set<int> numSet;
        numSet.insert(s[l]);
        int maxLen = -1, currLen = 1;;
        while(r < n){
            while(l < r && numSet.find(s[r]) != numSet.end()){
                numSet.erase(s[l]);
                l++;
            }
            currLen = numSet.size();
            maxLen = max(maxLen,currLen);
            numSet.insert(s[r]);
            r++;
        }
        return maxLen+1;
    }
};