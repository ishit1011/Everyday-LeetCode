class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        vector<int> arr;
        int n = tasks.size();
        for(int i=0; i<n; i++){
            int endTime = tasks[i][0] + tasks[i][1];
            arr.push_back(endTime);
        }
        sort(arr.begin(),arr.end());
        return arr[0];
    }
};