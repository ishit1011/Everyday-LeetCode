class Solution {
public:
    void dfsSolve(vector<vector<int>>& land, int i, int j, int& ri, int& rj){
        int n = land.size(), m = land[0].size();
        if(i >= 0 && i < n && j >= 0 && j < m && land[i][j] == 1){
            ri = max(ri,i);
            rj = max(rj,j);
            land[i][j] = 0;
        }
        else{
            return;
        }
        dfsSolve(land,i,j+1,ri,rj);
        dfsSolve(land,i,j-1,ri,rj);
        dfsSolve(land,i+1,j,ri,rj);
        dfsSolve(land,i-1,j,ri,rj);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int n = land.size(), m = land[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(land[i][j] == 1){
                    int li = i, lj = j, ri = i, rj = j;
                    dfsSolve(land,i,j,ri,rj);
                    ans.push_back({li,lj,ri,rj});
                }
            }
        }
        return ans;
    }
};