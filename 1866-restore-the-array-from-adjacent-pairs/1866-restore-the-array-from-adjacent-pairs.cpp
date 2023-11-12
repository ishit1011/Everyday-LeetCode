class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& adj,int curr,
    set<int>& visited, vector<int>& ans){
        if(visited.find(curr) != visited.end()){
            return;
        }
        visited.insert(curr);
        ans.push_back(curr);
        for(auto i : adj[curr]){
            dfs(adj,i,visited,ans);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> adjList;
        for(auto &i : adjacentPairs){
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }
        int head = 0;
        for(auto i:adjList){
            if(i.second.size() == 1){
                head = i.first;
                break;
            }
        }
        set<int> visited;
        vector<int>ans;
        dfs(adjList,head,visited,ans);
        return ans;
    }
};