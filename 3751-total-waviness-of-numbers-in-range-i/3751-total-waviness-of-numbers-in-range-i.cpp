class Solution {
public:
    int calcPV(string str){
        int ans = 0;
        for(int i=1; i<str.size()-1; i++){
            if(str[i]-'0' > str[i-1]-'0' && str[i]-'0' > str[i+1]-'0'){
                ans++;
            }
            if(str[i]-'0' < str[i-1]-'0' && str[i]-'0' < str[i+1]-'0'){
                ans++;
            }
        }
        return ans;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i=num1; i<=num2; i++){
            string str = to_string(i);
            ans += calcPV(str);
        }
        return ans;
    }
};