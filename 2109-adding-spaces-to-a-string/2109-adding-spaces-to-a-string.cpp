class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string str = "";
        int n = s.size(), m = spaces.size();;
        int j = 0;
        for(int i=0; i<n; i++){
            if(j < m && i == spaces[j]){
                str += ' ';
                j++;
            }
            str += s[i];
        }
        return str;
    }
};