class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        int cntChar = 1;
        char ch = word[0];
        string ans;
        for(int i=1; i<n; i++){
            if(word[i] == ch && cntChar < 9){
                cntChar++;
            }
            else{
                ans += to_string(cntChar) + ch;
                ch = word[i];
                cntChar = 1;
            }
        }
        ans += to_string(cntChar) + ch;
        return ans;
    }
};