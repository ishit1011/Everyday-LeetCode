class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cntOranges = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0){
                    cntOranges++;
                }
            }
        }
        vector<vector<bool>> isVis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    isVis[i][j] = true;
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>> dirs = {{0,-1},{0,1},{-1,0},{1,0}};
        int cntRotten = 0;
        int time = -1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int,int> pr = q.front();
                cntRotten++;
                q.pop();
                for(auto [x,y] : dirs){
                    int i = pr.first + x;
                    int j = pr.second + y;
                    if(i < n && i >= 0 && j < m && j >= 0 && grid[i][j] == 1 && isVis[i][j] == false){
                        isVis[i][j] = true;
                        grid[i][j] = 2;
                        q.push({i,j});
                    }
                }
            }
            time++;
        }
        cout<<"cntRotten : "<<cntRotten<<" cntOranges : "<<cntOranges<<endl;
        if(cntOranges == 0){
            return 0;
        }
        return (cntOranges != 0 && cntOranges == cntRotten) ? time : -1;
    }
};