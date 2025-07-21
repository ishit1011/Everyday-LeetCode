class Solution {
public:
    bool isAlphabet(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch>= 'A' && ch <= 'Z')){
            return true;
        }
        return false;
    }
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U'){
            return true;
        }
        return false;
    }
    bool isValid(string word) {
        int n = word.size();
        if(n < 3) return false;
        int vowelCnt = 0, consonantCnt = 0;
        for(int i=0; i<n; i++){
            if(!isdigit(word[i]) && !isAlphabet(word[i])){
                return false;
            }
            
            if(isAlphabet(word[i])){
                if(isVowel(word[i])){
                    vowelCnt++;
                }
                else{
                    consonantCnt++;
                }
            }
        }
        if(vowelCnt > 0 && consonantCnt > 0){
            cout<<vowelCnt<<" & "<<consonantCnt;
            return true;
        }
        return false;
    }
};