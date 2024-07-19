class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int numR = i, numC = j;
                int minR = INT_MAX, maxC = -1;
                for(int a=0; a<m; a++){
                    minR = min(minR,matrix[numR][a]);
                }
                for(int b=0; b<n; b++){
                    maxC = max(maxC,matrix[b][numC]);
                }
                if(matrix[numR][numC] == minR && matrix[numR][numC] == maxC){
                    ans.push_back(matrix[numR][numC]);
                }
            }
        }
        return ans;
    }
};