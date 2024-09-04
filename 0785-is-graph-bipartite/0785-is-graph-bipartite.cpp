class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node){
        int parentColor = color[node];
        for(int j=0; j<graph[node].size(); j++){
            int neighbour = graph[node][j];
            if(color[neighbour] == -1){
                color[neighbour] = !parentColor;
                cout<<"\nxxColor of idx : "<<neighbour<<" = "<<color[neighbour]<<"\n";
                if(!dfs(graph,color,neighbour)){
                    return false;
                }
            }
            else if(color[neighbour] == parentColor){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                color[i] = 0;
                cout<<"Color of idx : "<<i<<" = "<<color[i];
                if(dfs(graph,color,i) == false){
                    return false;
                }
            }
        }
        return true;
    }
};