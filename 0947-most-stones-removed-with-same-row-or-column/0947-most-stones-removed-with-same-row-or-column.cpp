class Solution {
public:
    void dfs(vector<vector<int>>& stones, int i,vector<bool>& isVis, int& n){
        isVis[i] = true;
        for(int row=0; row<n; row++){
            if(!isVis[row]){
                // same row elements
                if(stones[row][0] == stones[i][0]){
                    dfs(stones,row,isVis,n);
                }
                // same col elements
                if(stones[row][1] == stones[i][1]){
                    dfs(stones,row,isVis,n);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        sort(stones.begin(),stones.end());
        vector<bool> isVis(n,false);

        int connectedElements = 0;
        for(int i=0; i<n; i++){
            if(!isVis[i]){
                dfs(stones,i,isVis,n);
                connectedElements++;
            }
        }
        return n - connectedElements;
    }
};