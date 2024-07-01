class Solution {
public:
    // up , down, right, left
    vector<int> xDirec = {-1,1,0,0};
    vector<int> yDirec = {0,0,1,-1};
    int solve(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
            return 0;
        }
        int initialVal = grid[i][j];
        grid[i][j] = 0;
        int val = 0;
        for(int k=0; k<4; k++){
            int x = i + xDirec[k];
            int y = j + yDirec[k];
            val = max(val,initialVal + solve(grid,x,y));
        }
        grid[i][j] = initialVal;
        return val;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0){
                    ans = max(ans,solve(grid,i,j));
                }
            }
        }
        return ans;
    }
};