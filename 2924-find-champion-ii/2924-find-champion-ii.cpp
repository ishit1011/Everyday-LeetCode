class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int N = edges.size();
        vector<int> indeg(n,0);
        for(int i=0; i<N; i++){
            indeg[edges[i][1]]++;
        }
        vector<int> ans;
        for(int i=0; i<n; i++){ 
            if(indeg[i] == 0){
                ans.push_back(i);
            }
        }
        return ans.size() == 1 ? ans[0] : -1;
    }
};