class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto& it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> cost(n,INT_MAX);
        cost[src] = 0;
        q.push({src,{0,0}});
        while(!q.empty()){
            int node = q.front().first;
            int currCost = q.front().second.first;
            int stepsLeft = q.front().second.second;
            q.pop();
            for(auto& neigh : adj[node]){
                if(currCost + neigh.second < cost[neigh.first] && stepsLeft <= k){
                    cost[neigh.first] = currCost + neigh.second;
                    q.push({neigh.first,{cost[neigh.first],stepsLeft+1}});
                }
            }
            
        }
        return (cost[dst] >= INT_MAX) ? -1 : cost[dst];
    }
};