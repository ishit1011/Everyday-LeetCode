class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> ans(n,vector<char>(m));

        // 1. Transpose
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = boxGrid[j][i];
            }
        }

        // 2. Reverse each row 
        for (int i = 0; i < n; i++) {
            reverse(ans[i].begin(), ans[i].end());
        }

        for(int j=0; j<m; j++){
            for(int i=n-1; i>=0; i--){
                if(ans[i][j] == '.'){
                    int nextStone = -1;
                    for(int k=i-1; k>=0; k--){
                        if(ans[k][j] == '*') break; // obstacle
                        if(ans[k][j] == '#') {
                            nextStone = k;
                            break;
                        }
                    }

                    if (nextStone != -1) {
                        ans[nextStone][j] = '.';
                        ans[i][j] = '#';
                    }
                }
            }
        }
        return ans;
    }
};