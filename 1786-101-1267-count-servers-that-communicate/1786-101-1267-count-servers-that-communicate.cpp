class Solution {
public:
    // *) 1 means that on that cell there is a server and 0 means that it is no server
    // *) Two servers communicate if on the same row or on the same column
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rowCnt(m,0), colCnt(n,0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }
        int cntConnected = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    if(rowCnt[i] > 1 || colCnt[j] > 1){
                        cntConnected++;
                    }
                }
            }
        }
    
        return cntConnected;
    }
};