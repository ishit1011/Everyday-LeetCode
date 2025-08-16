class Solution {
public:
    int maximum69Number (int num) {
        string str = to_string(num);
        int i=0, n = str.size();
        while(i<n && str[i] == '9'){
            i++;
        }
        if(i < n){
            str[i] = '9';
        }
        int ans = stoi(str);
        return ans;
    }
};