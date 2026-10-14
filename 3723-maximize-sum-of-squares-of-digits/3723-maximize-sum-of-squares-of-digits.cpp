class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        vector<int> p(num);
        int currSum = 0;
        for(int i=0; i<num; i++){
            int diff = sum-currSum;
            if(diff > 9) {
                p[i] = 9;
                currSum += 9;
            }
            else {
                p[i] = diff;
                currSum += diff;
            }
        }
        string ans = "";
        int tempSum = 0;
        for(int i=0; i<num; i++){
            ans += to_string(p[i]);
            tempSum += p[i];
        }
        return tempSum != sum ? "" : ans;
    }
};