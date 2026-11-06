class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        // O(m log m)
        sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        // x = 8
        // [1,11] [2,29] [1,32] [1,35] [1,39]
        // 11, 14, 15, 22, 23, 30, 31, 33, 34, 38

        // query[0] = 11 -> window = [3, 11]
        // logsL = 0, logsR = 0 --> log : [server = 1, time = 11] -> YES
        // logsL = 0, logsR = 1 --> log : [server = 2, time = 29] -> NO ==> break

        // query[1] = 14 -> window = [6, 14]
        // logsL = 0, logsR = 1 --> log : [server = 2, time = 29] -> NO

        int sz = queries.size();
        vector<pair<int,int>> tmpQueries;
        for(int i=0; i<sz; i++){
            tmpQueries.push_back({queries[i],i});
        }

        // O(sz log sz)
        sort(tmpQueries.begin(),tmpQueries.end());

        vector<int> ans(sz,-1);
        vector<int> serverCnts(n+1,0);
        
        int logsL = 0, logsR = 0, activeServers = 0;

        // O(sz * m)
        for(int i=0; i<sz; i++){
            int queryL = tmpQueries[i].first-x, queryR = tmpQueries[i].first;

            // 1. bring logsL to query time window minima
            while(logsL < logs.size() && logs[logsL][1] < queryL){
                serverCnts[logs[logsL][0]]--;
                if(serverCnts[logs[logsL][0]] == 0) activeServers--;
                logsL++;
            }
            // 2. start moving R & check if under query time window maxima
            while(logsR < logs.size() && logs[logsR][1] <= queryR){
                if(serverCnts[logs[logsR][0]] == 0) activeServers++;
                serverCnts[logs[logsR][0]]++;
                logsR++;
            }
            // 3. sub unique servers in this query window from total servers
            ans[tmpQueries[i].second] = n - activeServers;
        }
        return ans;

    }
};