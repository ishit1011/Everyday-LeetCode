class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int li = 0, ri = n-1;
        while(li < ri){
            if(!isalnum(s[li])){
                li++;
            }
            else if(!isalnum(s[ri])){
                ri--;
            }
            else if(tolower(s[li]) != tolower(s[ri])){
                return false;
            }
            else{
                li++;
                ri--;
            } 
        }
        return true;
    }
};