class Solution {
public:
    void dfs(int n, vector<vector<int>>& paths, vector<vector<int>>& adj, int node, vector<int>& colors){
        unordered_set<int> unavailColors;
        // check karle neighbours pe kaunse flowers hai --> set mai daal le
        for(int neigh : adj[node]){
            if(colors[neigh] != -1){
                unavailColors.insert(colors[neigh]);
            }
        }
        // neighbours ke color ke alaawa milne waala pahla color assign karde curr node ko
        for(int i=1; i<=4; i++){
            // agar koi color availaible hai toh turant assign karde
            if(unavailColors.find(i) == unavailColors.end()){
                colors[node] = i;
                break;
            }
        }
        // dfs recursively chala de curr node ke neighbours pe --> agar uncolored honge to "dfs" se color ho jaayenge
        for(int neigh : adj[node]){
            if(colors[neigh] == -1){
                dfs(n,paths,adj,neigh,colors);
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for (const auto& path : paths) {
            adj[path[0] - 1].push_back(path[1] - 1); // Subtract 1 for 0-based indexing
            adj[path[1] - 1].push_back(path[0] - 1);
        }

        vector<int> colors(n,-1);
        for(int i=0; i<n; i++){
            if(colors[i] == -1){
                dfs(n,paths,adj,i,colors);
            }
        }

        return colors;
    }
};