class Solution {
public:
    int checkIsland(vector<vector<int>>& grid, vector<vector<int>>& isvis, int i, int j, int n, int m){
        if(isvis[i][j]) return 1;
        if(grid[i][j] == 0){
            if(i == 0 || j == 0 || i == n-1 || j == m-1) return 0;
        }
        if(grid[i][j] == 1) return 1;

        isvis[i][j] = true;
        int left = checkIsland(grid,isvis,i,j-1,n,m); 
        int right = checkIsland(grid,isvis,i,j+1,n,m); 
        int up = checkIsland(grid,isvis,i-1,j,n,m); 
        int down = checkIsland(grid,isvis,i+1,j,n,m);

        return left & right & up & down;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> isvis(n,vector<int>(m,false));
        int ans = 0;
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(grid[i][j] == 0 && !isvis[i][j]){
                    int closed = checkIsland(grid,isvis,i,j,n,m);
                    ans += closed;
                }
                
            }
        }
        return ans;
    }
};