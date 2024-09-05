class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        vector<int> missingNum(n);
        int sum = 0;
        for(int i=0; i<m; i++){
            sum += rolls[i];
        }
        int s = (mean * (n + m)) - sum;
        if(s > 6 * n || s < 1 * n){
            return {};
        }
        int remainingMean = s/n;
        for(int i=0; i<n; i++){
            missingNum[i] = remainingMean;
        }
        int remainingVal = s % n;
        for(int i=0; i<remainingVal; i++){
            missingNum[i]++;
        }
        return missingNum;
    }
};