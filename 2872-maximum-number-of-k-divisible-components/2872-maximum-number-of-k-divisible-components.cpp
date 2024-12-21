class Solution {
public:
    int count = 0;
    int dfs(int curr, int prev, vector<vector<int>> &adj, vector<int>& values, int k){
        int sum = 0;
        for(int node : adj[curr]){
            if(node == prev) continue;
            sum += dfs(node,curr,adj,values,k);
        }
        sum += values[curr]; 
        sum %= k;
        if(sum == 0) count++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0,-1,adj,values,k);
        return count;
    }
};