class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> mp1;
        vector<string> mp2;
        string temp1 = "",temp2 = "";
        for(char ch : s1){
            if(ch == ' '){
                mp1.push_back(temp1);
                temp1 = "";
            }
            else{
                temp1 += ch;
            }
        }
        mp1.push_back(temp1);
        for(char ch : s2){
            if(ch == ' '){
                mp2.push_back(temp2);
                temp2 = "";
            }
            else{
                temp2 += ch;
            }
        }
        mp2.push_back(temp2);
        vector<string> ans;
        for(string s : mp1){
            if(find(mp2.begin(), mp2.end(), s) == mp2.end() && count(mp1.begin(), mp1.end(), s) == 1){
                ans.push_back(s);
            }
        }
        for(string s : mp2){
            if(find(mp1.begin(), mp1.end(), s) == mp1.end() && count(mp2.begin(),mp2.end(),s) == 1){
                ans.push_back(s);
            }
        }
        return ans;
    }
};