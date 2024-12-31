class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int n, int i, vector<int>& dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        ans = min(ans,costs[0]+solve(days,costs,n,i+1,dp));
        int ptr1 = i;
        while(ptr1<n && days[ptr1] <= days[i]+6){
            ptr1++;
        }
        ans = min(ans,costs[1]+solve(days,costs,n,ptr1,dp));

        int ptr2 = i;
        while(ptr2<n && days[ptr2] <= days[i]+29){
            ptr2++;
        }
        ans = min(ans,costs[2]+solve(days,costs,n,ptr2,dp));
        
        return dp[i] = ans;
    } 
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n,-1);
        return solve(days,costs,n,0,dp);
    }
};