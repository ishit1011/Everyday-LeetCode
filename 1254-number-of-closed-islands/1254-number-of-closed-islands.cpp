class Solution {
public:
    int checkIsland(vector<vector<int>>& grid, vector<vector<int>>& isvis, int i, int j, int n, int m){
        if(isvis[i][j]) return 1;
        if(grid[i][j] == 0){
            if(i == 0 || j == 0 || i == n-1 || j == m-1) return 0;
        }
        if(grid[i][j] == 1) return 1;

        isvis[i][j] = true;
        int left = checkIsland(grid,isvis,i,j-1,n,m); // left
        int right = checkIsland(grid,isvis,i,j+1,n,m); // right
        int up = checkIsland(grid,isvis,i-1,j,n,m); // up
        int down = checkIsland(grid,isvis,i+1,j,n,m); // down

        return left & right & up & down;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> isvis(n,vector<int>(m,false));
        int ans = 0;
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(grid[i][j] == 0 && !isvis[i][j]){
                    // cout<<"i : "<<i<<" j : "<<j<<endl;
                    int closed = checkIsland(grid,isvis,i,j,n,m);
                    // cout<<"closed : "<<closed<<endl;
                    ans += closed;

                    
                    // for(int k=0; k<n; k++){
                    //     for(int l=0; l<m; l++){
                    //         cout<<"isvis ["<<k<<"]["<<l<<"] : "<<isvis[k][l]<<" ";
                    //     }
                    //     cout<<"\n";
                    // }
                }
                
            }
        }
        return ans;
    }
};