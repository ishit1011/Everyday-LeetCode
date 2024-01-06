class Solution {
public:
    /*
    int solve(vector<int>& startTime, vector<int>& endTime, vector<int>& profit, int i){
        if(i == profit.size()) return 0;
        int ind = lower_bound(startTime.begin(), startTime.end(), endTime[i]) - startTime.begin();
        int takeSum = solve(startTime, endTime, profit, ind) + profit[i];
        int notTakeSum = solve(startTime, endTime, profit, i+1);
        return max(takeSum,notTakeSum);
    }
    */
    int solveMem(vector<int>& startTime, vector<int>& endTime, vector<int>& profit, int i, vector<int>& dp){
        if(i == profit.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ind = lower_bound(startTime.begin(), startTime.end(), endTime[i]) - startTime.begin();
        int takeSum = solveMem(startTime, endTime, profit, ind,dp) + profit[i];
        int notTakeSum = solveMem(startTime, endTime, profit, i+1,dp);
        return dp[i] = max(takeSum,notTakeSum);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        set<pair<int,pair<int,int>>> st;
        for(int i=0; i<n; i++){
            st.insert({startTime[i],{endTime[i], profit[i]}});
        }

        int i = 0;
        for(auto it:st){
            pair<int,pair<int,int>> p = it;
            startTime[i] = p.first;
            endTime[i] = p.second.first;
            profit[i] = p.second.second;

            i = i + 1;
        }
        vector<int> dp(n+1,-1);
        return solveMem(startTime, endTime, profit, 0,dp);
    }
};