class Solution {
public:
    int solve(int i,int j, int k, vector<vector<int>>& grid, int m, int n, vector<vector<vector<int>>> &dp){
        if(i >= grid.size() || j >= grid[0].size() || (k == 0 && grid[i][j]>0)){
            return INT_MIN;
        }
        if(i == m-1 && j == n-1){
            return grid[i][j];
        }
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }

        int rightScore = grid[i][j] + solve(i,j+1,k-(grid[i][j]>0),grid,m,n,dp);
        int downScore = grid[i][j] + solve(i+1,j,k-(grid[i][j]>0),grid,m,n,dp);

        return dp[i][j][k] = max(downScore,rightScore);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>> (n+1,vector<int> (k+1,-1)));
        int ans = solve(0,0,k,grid,m,n,dp);
        
        return ans < 0 ? -1 : ans;
    }
};