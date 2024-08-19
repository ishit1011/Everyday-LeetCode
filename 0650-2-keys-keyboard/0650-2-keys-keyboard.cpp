class Solution {
public:
    int solve(int noteLen, int clipLen, int n, vector<vector<int>>& dp) {
        if (noteLen == n) return 0;
        if (noteLen > n) return INT_MAX / 2;
        if(dp[noteLen][clipLen] != -1){
            return dp[noteLen][clipLen];
        }

        int copyAndPaste = 2 + solve(noteLen * 2, noteLen, n, dp);
        int pasteOnly = 1 + solve(noteLen + clipLen, clipLen, n, dp);

        return dp[noteLen][clipLen] = min(copyAndPaste, pasteOnly);
    }
    int minSteps(int n) {
        if (n == 1) return 0;
        vector<vector<int>> dp(1000,vector<int>(1000,-1));
        return 1 + solve(1, 1, n, dp);
    }
};