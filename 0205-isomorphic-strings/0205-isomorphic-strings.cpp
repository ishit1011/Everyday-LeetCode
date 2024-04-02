class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> St, Ts;
        for(int i=0; i<s.size(); i++){
            if(St.count(s[i]) == 0 && Ts.count(t[i]) == 0){
                St.insert(make_pair(s[i],t[i]));
                Ts.insert(make_pair(t[i],s[i]));    
            }
            else{
                if(St[s[i]] != t[i] || Ts[t[i]] != s[i]){
                    return false;
                }
            }
        }
        return true;
    }
};