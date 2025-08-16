class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size(), i = 0;
        int maxNum = -1;
        while(i<n){
            int j=i+1;
            char digit = num[i];
            while(j<n && num[j] == digit){
                j++;
            }
            if(j-i >= 3){
                int temp = digit - '0';
                maxNum = max(maxNum,temp);
            }
            i = j;
        }
        string ans, tempNum = to_string(maxNum);
        for(int i=0; i<3; i++){
            ans += tempNum;
        }
        return maxNum == -1 ? "" : ans;
    }
};