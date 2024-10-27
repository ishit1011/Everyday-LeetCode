class Solution {
public:
    int solve(vector<vector<int>>& matrix, int n, int m, int i, int j, vector<vector<int>> &dp){
        if(i<0 || i>=n || j<0 || j>=m || matrix[i][j] == 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = solve(matrix,n,m,i,j+1,dp);
        int bottom = solve(matrix,n,m,i+1,j,dp);
        int btRight = solve(matrix,n,m,i+1,j+1,dp);
        return dp[i][j] = 1 + min({right,bottom,btRight});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 1){
                    ans += solve(matrix,n,m,i,j,dp);
                }
            }
        }

        return ans;
    }
};