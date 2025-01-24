class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // check for loop in Directed Graph : Khan's Algo [Topological Sort]
        // change direction of given graph reverse & find nodes not in loop
        int n = graph.size();
        vector<int> safeNodes;
        vector<int> inDeg(n,0);
        vector<vector<int>> revGraph(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<graph[i].size(); j++){
                revGraph[graph[i][j]].push_back(i);
                inDeg[i]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(inDeg[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            safeNodes.push_back(ele);
            for(int neigh : revGraph[ele]){
                inDeg[neigh]--;
                if(inDeg[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};