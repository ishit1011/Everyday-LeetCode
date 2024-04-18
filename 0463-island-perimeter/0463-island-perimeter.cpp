class Solution {
public:
    int solveDfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
            return 1;
        }
        if(grid[i][j] == -1){
            return 0;
        }
        grid[i][j] = -1;
        return (solveDfs(grid,i+1,j) + solveDfs(grid,i-1,j) + 
                solveDfs(grid,i,j+1) + solveDfs(grid,i,j-1));
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    ans += solveDfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};