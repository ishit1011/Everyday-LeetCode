class Solution {
public:
    //-------------------- Djikstra Approach ----------------
    int bfs(vector<vector<int>> &adj, int n){
        vector<int> djikstraDist(n,INT_MAX);
        djikstraDist[0] = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            for(int neigh : adj[ele]){
                if(djikstraDist[neigh] > djikstraDist[ele]+1){
                    djikstraDist[neigh] = djikstraDist[ele]+1;
                    q.push(neigh);
                }
            }
        }
        return djikstraDist[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adjList(n);
        for(int i=0; i<n-1; i++){
            adjList[i].push_back(i+1);
        }
        vector<int> ans;
        int N = queries.size();
        for(int i=0; i<N; i++){
            adjList[queries[i][0]].push_back(queries[i][1]);
            int len = bfs(adjList,n);
            ans.push_back(len);
        }
        return ans;
    }
};