class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = word.find(ch);
        reverse(word.begin(), word.begin() + index + 1);
        return word;
    }
};