class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        // 1. Make adjacency list & declare every node as unvisited
        unordered_map<int,vector<int>> graph;
        unordered_map<int,bool> isVisited;
        for(auto x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);

            isVisited[x[0]] = false;
            isVisited[x[1]] = false;
        }

        // 2. BFS
        queue<int> q;
        q.push(source);
        isVisited[source] = true;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();

            vector<int> adjList = graph[u];
            
            for(int v=0; v<adjList.size(); v++){
                if(isVisited[adjList[v]] == true){
                    continue;
                }
                else{
                    isVisited[adjList[v]] = true;
                    q.push(adjList[v]);
                }
            }
        }
        return isVisited[destination];
    }
};