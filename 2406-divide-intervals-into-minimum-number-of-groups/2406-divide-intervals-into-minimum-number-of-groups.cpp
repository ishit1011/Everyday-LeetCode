class Solution {
public:
    int minGroups(vector<vector<int>>& arr) {
        // Max overlapping intervals for an index in the "arr" = MIN. no. of separate groups required

        //  1. Set start & end values for each event
        int n = arr.size();
        vector<pair<int,int>> eventStartEnd;
        for(int i=0; i<n; i++){
            int s = arr[i][0];
            int e = arr[i][1];
            eventStartEnd.push_back({s,1});
            eventStartEnd.push_back({e+1,-1});
        }

        // 2. Sort the events start & end times
        sort(eventStartEnd.begin(),eventStartEnd.end());

        // 3. Find prefixSum for start & end times of all events & RETURN max prefixSum
        int preSum = 0, maxPreSum = 0;
        for(auto [x,y] : eventStartEnd){
            preSum += y;
            maxPreSum = max(maxPreSum,preSum);
        }
        return maxPreSum;
    }
};