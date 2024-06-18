class Solution {
public:
    string rle(string s){
        if(s.empty()){
            return "1";
        }
        string tmp = "";
        int i = 0, j = 0; 
        while(i < s.length()){
            int cnt = 0;
            while(j < s.length() && s[i] == s[j]){
                j++;
            }
            cnt = j-i;
            tmp += to_string(cnt) + s[i]; 
            i = j;
        }
        return tmp;
    }
    string countAndSay(int n) {
        if(n == 1) return "1";
        string tmp = "1";
        int i = 1;
        while(i < n){
            cout<<"temp : "<<tmp<<endl;
            tmp = rle(tmp);
            cout<<"temp : "<<tmp<<endl;
            cout<<"-------\n";
            i++;
        }
        return tmp;
    }
};