class Solution {
public:
    // int solve(vector<int>& arr, int k, int index){
    //     int n = arr.size();
    //     if(index >= n) return 0;
        
    //     int currMax = 0, ans = 0;
    //     for(int i=index; i<min(index+k,n); i++){
    //         currMax = max(currMax,arr[i]);
    //         ans = max(ans, (i-index+1)*currMax + solve(arr,k,index+1));
    //     }
    //     return ans;
    // }
    int solveMem(vector<int>& arr, int k, int index, vector<int>& dp){
        int n = arr.size(), currMax = 0, ans = 0;
        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];
        for(int i=index; i<min(index+k,n); i++){
            currMax = max(currMax,arr[i]);
            ans = max(ans, (i-index+1)*currMax + solveMem(arr,k,i+1,dp));
        }
        dp[index] = ans;
        return ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        // return solve(arr,k,0);
        return solveMem(arr,k,0,dp);
    }
};