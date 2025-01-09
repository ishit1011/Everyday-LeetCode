class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        int prefLen = pref.length();
        for (string word : words) {
            if (word.length() >= prefLen) {
                if (word.substr(0, prefLen) == pref) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};