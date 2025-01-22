class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> height(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j]){
                    height[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            // Down
            if(x+1 < m && height[x+1][y] == -1){
                height[x+1][y] = height[x][y]+1;
                q.push({x+1,y});
            }   
            // Right
            if(y+1 < n && height[x][y+1] == -1){
                height[x][y+1] = height[x][y]+1;
                q.push({x,y+1});
            }
            // Up
            if(x > 0 && height[x-1][y] == -1){
                height[x-1][y] = height[x][y]+1; 
                q.push({x-1,y});
            } 
            // Left
            if(y > 0 && height[x][y-1] == -1){
                height[x][y-1] = height[x][y]+1;
                q.push({x,y-1});
            }
        }
        return height;
    }
};