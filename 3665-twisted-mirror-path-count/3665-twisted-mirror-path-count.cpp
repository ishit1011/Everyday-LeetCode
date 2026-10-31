class Solution {
public:
    long long MOD = 1e9 + 7; 
    int solve(vector<vector<int>>& grid, int i, int j, bool lastStep, int m, int n, vector<vector<vector<int>>> &dp){
        if(i < 0 || j < 0 || i == m || j == n) return 0;
        if(i == m-1 && j == n-1) return 1;

        if(dp[i][j][lastStep] != -1) return dp[i][j][lastStep];

        int rTotal = 0, dTotal = 0;
        // laststep : T = right, F = down
        if(grid[i][j] == 1 && lastStep == true){
            dTotal = solve(grid,i+1,j,false,m,n,dp);
        }
        if(grid[i][j] == 1 && lastStep == false){
            rTotal = solve(grid,i,j+1,true,m,n,dp);
        }
        if(grid[i][j] == 0){
            rTotal = solve(grid,i,j+1,true,m,n,dp);
            dTotal = solve(grid,i+1,j,false,m,n,dp);
        }

        return dp[i][j][lastStep] = (rTotal + dTotal) % MOD;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, -1)));

        int down = solve(grid,0,0,false,m,n,dp);
        int right = solve(grid,0,0,true,m,n,dp);

        
        int ans = (down + right) / 2;

        return ans % MOD;
    }
};