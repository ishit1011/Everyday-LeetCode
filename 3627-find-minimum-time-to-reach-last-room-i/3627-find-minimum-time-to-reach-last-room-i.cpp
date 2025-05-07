class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));  // dist arr : from djikstra [find min time]

        pq.push({0,{0,0}});
        time[0][0] = 0;

        
        while(!pq.empty()){
            auto topEle = pq.top();
            pq.pop();
            int currTime = topEle.first, x = topEle.second.first, y = topEle.second.second;

            if(x == n-1 && y == m-1){
                return currTime;
            }

            if(x > 0) {
                int nextTime = max(currTime, moveTime[x-1][y]) + 1;
                if (nextTime < time[x-1][y]) {
                    time[x-1][y] = nextTime;
                    pq.push({nextTime, {x-1, y}});
                }
            }
            if(x < n-1){
                int nextTime = max(currTime, moveTime[x+1][y]) + 1;
                if (nextTime < time[x+1][y]) {
                    time[x+1][y] = nextTime;
                    pq.push({nextTime, {x+1, y}});
                }
            }
            if(y > 0){
                int nextTime = max(currTime, moveTime[x][y-1]) + 1;
                if (nextTime < time[x][y-1]) {
                    time[x][y-1] = nextTime;
                    pq.push({nextTime, {x, y-1}});
                }
            }
            if(y < m-1){
                int nextTime = max(currTime, moveTime[x][y+1]) + 1;
                if (nextTime < time[x][y+1]) {
                    time[x][y+1] = nextTime;
                    pq.push({nextTime, {x, y+1}});
                }
            }
        }
        return -1;
    }
};