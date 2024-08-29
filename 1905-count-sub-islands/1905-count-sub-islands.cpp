class Solution {
public:
    void dfs(vector<vector<int>>& grid2, int i, int j, vector<pair<int,int>>& row, vector<vector<bool>>& isVis){
        if(i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size() || grid2[i][j] == 0 || isVis[i][j] == true){
            return;
        }
        isVis[i][j] = true;
        row.push_back({i,j});
        dfs(grid2,i,j+1,row,isVis);
        dfs(grid2,i,j-1,row,isVis);
        dfs(grid2,i+1,j,row,isVis);
        dfs(grid2,i-1,j,row,isVis);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();
        vector<vector<bool>> isVis(n,vector<bool>(m,false));
        vector<vector<pair<int,int>>> check;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j] == 1 && isVis[i][j] == false){
                    vector<pair<int,int>> row;
                    dfs(grid2,i,j,row,isVis);
                    check.push_back(row);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<check.size(); i++){
            int c = true;
            for(auto [x,y] : check[i]){
                if(grid1[x][y] != 1){
                    c = false;
                }
            }
            if(c == true){
                ans++;
            }
        }
        return ans;
    }
};