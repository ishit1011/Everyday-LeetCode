class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            string temp = words[i];
            reverse(temp.begin(),temp.end());
            if(words[i] == temp) return words[i];
        }
        return "";
    }
};