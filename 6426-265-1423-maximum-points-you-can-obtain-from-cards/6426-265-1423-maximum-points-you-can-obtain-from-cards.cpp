class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = 0, minSum = INT_MAX, maxLen = n-k, totalSum = 0, currSum = 0;
        for(int i=0; i<n; i++){
            totalSum += cardPoints[i];
        }
        for(int r=0; r<n; r++){
            if(maxLen == 0){
                return totalSum;
            }
            currSum += cardPoints[r];
            if(r-l+1 >= maxLen){
                minSum = min(minSum,currSum);
                currSum -= cardPoints[l];
                l++;
            }
        }
        cout<<"maxLen : "<<maxLen<<" minSum : "<<minSum<<" totalSum : "<<totalSum<<endl;
        return totalSum-minSum;
    }
};