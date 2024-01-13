class Solution {
public:
    int countVowels(string s, int start, int end){
        int count = 0; 
        for(int i=start; i<end; i++){
            if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
            s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
            s[i] == 'u' || s[i] == 'U'){
                count++;
            }
        }
        return count;
    }
    bool halvesAreAlike(string s) {
        int len = s.size();
        int leftCount = countVowels(s,0,len/2);
        int rightCount = countVowels(s,len/2,len);
        return (leftCount == rightCount);
    }
};