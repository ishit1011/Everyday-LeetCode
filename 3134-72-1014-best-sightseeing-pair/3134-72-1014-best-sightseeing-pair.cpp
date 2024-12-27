class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int curr = values[0], finalSum = curr;
        for(int j=1; j<n; j++){
            finalSum = max(finalSum,curr+values[j]-j);
            curr = max(curr,values[j]+j);
        }
        return finalSum;
    }
};