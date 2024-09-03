class Solution {
public:
    int getLucky(string s, int k) {
        int n = s.size();
        string num = "";

        for(int i=0; i<n; i++){
            int temp = s[i] - 'a' + 1;
            num += to_string(temp);
        }
        int sum;
        for(int i=0; i<k; i++){
            sum = 0;
            for(char ch : num){
                sum += ch - '0';
            }
            num = to_string(sum);
        }
        return sum;
    }
};