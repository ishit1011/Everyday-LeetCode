class Solution {
public:
    string makeFancyString(string s) {
        if(s.size() <= 2){
            return s;
        }
        string str = "";
        str += s[0];
        str += s[1];
        int n = s.size();
        for(int i=2; i<n; i++){
            if(s[i] == s[i-1] && s[i] == s[i-2]){
                continue;
            }
            str += s[i];
        }
        return str;
    }
};