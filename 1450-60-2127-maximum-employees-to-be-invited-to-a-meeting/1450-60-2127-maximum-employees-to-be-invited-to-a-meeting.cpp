class Solution {
public:
    int maximumInvitations(vector<int>& fav) {
        // Finding Cycle in Directed Graph (Topo Sort) + check for chains & mayCyclelen
        // 1. Find all connected chains
        // 2. Check for all loops --> Loops of len = 2 : can be part of chains
        //                        --> Loops of len > 2 : find maxCycleLen of those  
        int n = fav.size();
        vector<int> indeg(n,0);
        for(int i=0; i<n; i++){
            indeg[fav[i]]++;
        }
        queue<int> q;
        vector<bool> isVis(n,false);
        vector<int> chainLen(n,0);
        for(int i=0; i<n; i++){
            if(indeg[i] == 0) q.push(i);
        }
        // Check for all chains connected in single largest line
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            isVis[curr] = true;
            chainLen[fav[curr]] = chainLen[curr]+1;
            if(--indeg[fav[curr]] == 0) q.push(fav[curr]);

        }
        // Now only all cycles are left 
        // 2 types of cycles : len == 2 / len > 2
        int maxCycleLen = 0, totalChainLen = 0;
        for(int i=0; i<n; i++){
            if(!isVis[i]){
                int node = i, currCycleLen = 0;
                while(!isVis[node]){
                    isVis[node] = true;
                    node = fav[node];
                    currCycleLen++;
                }
                if(currCycleLen == 2){
                    totalChainLen += 2 + chainLen[i] + chainLen[fav[i]];
                }
                else{
                    maxCycleLen = max(maxCycleLen,currCycleLen);
                }
            }
        }
        return max(maxCycleLen,totalChainLen);
    }
};