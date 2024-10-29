class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, int n, int m, vector<vector<int>> &dp){
        if(i < 0 || i >= n || j < 0 || j >= m){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int topR = 0, R = 0, bottomR = 0;
        int curr = grid[i][j];
        if(i-1 >= 0 && j+1 < m && grid[i-1][j+1] > curr){
            topR = 1 + solve(grid,i-1,j+1,n,m,dp);
        }
        if(i >= 0 && j+1 < m && grid[i][j+1] > curr){
            R = 1 + solve(grid,i,j+1,n,m,dp);
        }
        if(i+1 < n && j+1 < m && grid[i+1][j+1] > curr){
            bottomR = 1 + solve(grid,i+1,j+1,n,m,dp);
        }
        return dp[i][j] = max({topR,R,bottomR});
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = -1;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0; i<n; i++){
            ans = max(ans,solve(grid,i,0,n,m,dp));
        }
        return ans;
    }
};