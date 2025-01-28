class Solution {
public:
    vector<pair<int,int>> direc = {{0,1},{1,0},{0,-1},{-1,0}};
    bool isSafe(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& isVis){
        return (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] != 0 && !isVis[i][j]);
    }
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& isVis){
        int ans = grid[i][j];
        isVis[i][j] = true;
        for(auto d : direc){
            int newX = i + d.first, newY = j + d.second;
            if(isSafe(grid,newX,newY,isVis)){
                ans += dfs(grid,newX,newY,isVis);
            }
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> isVis(m,vector<bool>(n,false));
        int res = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] > 0 && !isVis[i][j]){
                    res = max(res,dfs(grid,i,j,isVis));
                }
            } 
        }
        return res;
    }
};