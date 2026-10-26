class Solution {
public:
    long long islandTotal(vector<vector<int>>& grid, vector<vector<bool>>& isvis, int i, int j, int m, int n){
        if(i < 0 || j < 0 || i == m || j == n || isvis[i][j] || grid[i][j] == 0) return 0;

        isvis[i][j] = true;
        long long l = islandTotal(grid,isvis,i,j-1,m,n);
        long long r = islandTotal(grid,isvis,i,j+1,m,n);
        long long u = islandTotal(grid,isvis,i-1,j,m,n);
        long long d = islandTotal(grid,isvis,i+1,j,m,n);

        return grid[i][j]+l+r+u+d;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> isvis(m,vector<bool>(n,false));
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] > 0 && !isvis[i][j]){
                    cout<<"i : "<<i<<" j : "<<j;
                    long long sum = islandTotal(grid,isvis,i,j,m,n);
                    if(sum % k == 0) ans++;
                    cout<<" sum : "<<sum<<endl;
                }
            }
        }

        return ans;
    }
};