class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<string>> grid(m,vector<string>(n,"/"));

        for(int j=0; j<n; j++){
            grid[0][j] = ".";
        }
        
        for(int i=0; i<m; i++){
            grid[i][n-1] = ".";
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == "/"){
                    grid[i][j] = "#";
                }
            }
        }
        vector<string> ans;
        for(int i=0; i<m; i++){
            string str = "";
            for(int j=0; j<n; j++){
                str += grid[i][j];
            }
            ans.push_back(str);
        }
        return ans;
    }
};