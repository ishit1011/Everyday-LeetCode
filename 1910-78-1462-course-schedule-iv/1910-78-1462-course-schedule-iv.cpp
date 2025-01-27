class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<vector<int>> adjList(n);
        vector<int> indeg(n,0);
        for(int i=0; i<prerequisites.size(); i++){
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indeg[prerequisites[i][1]]++; 
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indeg[i] == 0) q.push(i);
        }
        unordered_map<int,unordered_set<int>> storePrereq;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int child : adjList[node]){
                // Direct Prerequisite
                storePrereq[child].insert(node);
                // Indirect Prereq
                for(auto parent : storePrereq[node]){
                    storePrereq[child].insert(parent);
                }
                if(--indeg[child] == 0){
                    q.push(child);
                }
            }
        }
        vector<bool> ans(queries.size(),false);
        for(int i=0; i<queries.size(); i++){
            int parent = queries[i][0], child = queries[i][1];
            for(int c : storePrereq[child]){
                if(c == parent){
                    ans[i] = true;
                    break;
                }
            }
        }
        return ans;
    }
};