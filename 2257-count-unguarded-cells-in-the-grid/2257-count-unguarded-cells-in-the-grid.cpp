class Solution {
public:
    const int UNGUARDED = 0;
    const int GUARDED = 1;
    const int GUARD = 2;
    const int WALL = 3;
    void dfs(int r, int c, vector<vector<int>> &grid, char direc){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == GUARD || grid[r][c] == 
        WALL){
            return;
        }
        grid[r][c] = GUARDED;
        if(direc == 'U') dfs(r-1,c,grid,'U');
        if(direc == 'D') dfs(r+1,c,grid,'D');
        if(direc == 'L') dfs(r,c-1,grid,'L');
        if(direc == 'R') dfs(r,c+1,grid,'R');
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,UNGUARDED));

        for(const auto& guard : guards){
            grid[guard[0]][guard[1]] = GUARD;
        }

        for(const auto& wall : walls){
            grid[wall[0]][wall[1]] = WALL;
        }

        for(const auto& g:guards){
            dfs(g[0]-1,g[1],grid,'U');
            dfs(g[0]+1,g[1],grid,'D');
            dfs(g[0],g[1]-1,grid,'L');
            dfs(g[0],g[1]+1,grid,'R');
        }
        int cnt = 0;
        for(const auto& r:grid){
            for(const auto& cell:r){
                if(cell == UNGUARDED){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};