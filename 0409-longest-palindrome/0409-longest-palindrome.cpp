class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> count;
        for(int i=0; i<s.size(); i++){
            count[s[i]]++;
        }
        int length = 0;
        bool oddFreq = false;
        for(auto x : count){
            if(x.second % 2 == 0){
                length += x.second;
            }
            else{
                length += x.second - 1;
                oddFreq = true;
            }
        }
        if(oddFreq == true){
            length++;
        }
        return length;
    }
};