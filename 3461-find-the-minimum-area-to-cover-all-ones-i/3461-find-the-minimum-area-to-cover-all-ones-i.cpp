class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int rowFirst = -1, rowLast = -1, colFirst = -1, colLast = -1;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=0; j<m; j++){
                sum += grid[i][j];
            }
            if(sum != 0 && rowFirst == -1) {
                rowFirst = i;
                break;
            }
            if(sum != 0 && rowLast == -1) rowLast = i;
        }
        for(int i=n-1; i>=0; i--){
            int sum = 0;
            for(int j=0; j<m; j++){
                sum += grid[i][j];
            }
            if(sum != 0 && rowLast == -1) {
                rowLast = i;
                break;
            }
        }

        for(int j=0; j<m; j++){
            int sum = 0;
            for(int i=0; i<n; i++){
                sum += grid[i][j];
            }
            if(sum != 0 && colFirst == -1) {
                colFirst = j;
                break;
            }
        }
        for(int j=m-1; j>=0; j--){
            int sum = 0;
            for(int i=0; i<n; i++){
                sum += grid[i][j];
            }
            if(sum != 0 && colLast == -1) {
                colLast = j;
                break;
            }
        }
        
        int breadth = rowLast-rowFirst+1, length = colLast-colFirst+1;
        cout<<"row 1st : "<<rowFirst<<" row last : "<<rowLast<<endl;
        cout<<"col 1st : "<<colFirst<<" col Last : "<<colLast<<endl;
        return breadth*length;
    }
};