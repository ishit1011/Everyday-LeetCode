class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        long long sum = 0;
        int smallestNum = INT_MAX;
        int cntNeg = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] < 0){
                    cntNeg++;
                }
                sum += abs(matrix[i][j]);
                smallestNum = min(smallestNum,abs(matrix[i][j]));
            }
        }
        cout<<cntNeg<<endl;
        if(cntNeg % 2 == 0){
            return sum;
        }
        return sum-2*smallestNum;
    }
};