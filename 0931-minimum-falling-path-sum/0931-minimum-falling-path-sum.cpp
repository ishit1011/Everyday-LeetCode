class Solution {
public:
    /*
    int solve(vector<vector<int>>& matrix, int i, int j){
        int n = matrix.size();
        if(j>=n || j<0) return INT_MAX;
        if(i == n-1) return matrix[i][j];

        int leftDown = solve(matrix,i+1,j-1);
        int down = solve(matrix,i+1,j);
        int rightDown = solve(matrix,i+1,j+1);

        return matrix[i][j] + min(leftDown,min(down,rightDown));
    }
    */
    int solveMem(vector<vector<int>>& matrix, int i, int j,vector<vector<int>>& dp){
        int n = matrix.size();
        if(j>=n || j<0) return INT_MAX;
        if(i == n-1) return matrix[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];

        int leftDown = solveMem(matrix,i+1,j-1,dp);
        int down = solveMem(matrix,i+1,j,dp);
        int rightDown = solveMem(matrix,i+1,j+1,dp);

        return dp[i][j] = matrix[i][j] + min(leftDown,min(down,rightDown));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            int temp = solveMem(matrix,0,i,dp);
            ans = min(ans,temp);
        }
        return ans;
    }
};