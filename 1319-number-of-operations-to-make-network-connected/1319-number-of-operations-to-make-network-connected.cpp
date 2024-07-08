class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& adjList, vector<bool>& isVis, int start){
        if(isVis[start] == true) return;

        isVis[start] = true;
        for(auto &i : adjList[start]){
            if(isVis[i] == false){
                dfs(adjList,isVis,i);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        int size = c.size();
        if(size <  n-1) return -1;

        unordered_map<int,vector<int>> adjList;
        for(int i=0; i<size; i++){
            adjList[c[i][0]].push_back(c[i][1]);
            adjList[c[i][1]].push_back(c[i][0]); 
        }
        int cntVis = 0; 
        vector<bool> isVis(n,false);
        for(int i=0; i<n; i++){
            if(isVis[i] == false){
                cntVis++;
                dfs(adjList,isVis,i);
            }
        }
        return cntVis-1;
    }
};