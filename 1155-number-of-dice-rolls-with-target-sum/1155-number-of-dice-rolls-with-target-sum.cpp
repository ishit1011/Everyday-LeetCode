class Solution {
public:
    /*              1. Recursion
    int solve(int dices, int faces, int target){
        if(target < 0){
            return 0;
        }
        if(dices == 0 && target != 0){
            return 0;
        }
        if(target == 0 && dices != 0){
            return 0;
        }
        if(dices == 0 && target == 0){
            return 1;
        }

        int ans = 0;
        for(int i=1; i<=faces; i++){
            ans = ans + solve(dices-1, faces, target-i);
        }
        return ans;
    }*/
    int mod = 1e9+7;
    /*                  2. Recursion + Memoization
    int solveMem(int dices, int faces, int target, vector<vector<int>>& dp){
        if(target < 0){
            return 0;
        }
        if(dices == 0 && target != 0){
            return 0;
        }
        if(target == 0 && dices != 0){
            return 0;
        }
        if(dices == 0 && target == 0){
            return 1;
        }
        if(dp[dices][target] != -1){
            return dp[dices][target];
        }

        int ans = 0;
        for(int i=1; i<=faces; i++){
            ans = (ans + solveMem(dices-1, faces, target-i,dp)) % mod;
        }
        return dp[dices][target] = ans;
    }*/
    /*                  3. Tabulation
    int solveTab(int d, int f, int t){
        vector<vector<int>>dp(d+1,vector<int>(t+1,0));
        // Analysing base cases
        dp[0][0] = 1;

        // Loop for Bottom-Up Approach --> dices (0 --> d) && target (0 --> t)
        for(int dices=1; dices<=d; dices++){
            for(int target=1; target<=t; target++){
                int ans = 0;
                for(int i=1; i<=f; i++){
                    if(target >= i){
                        ans = (ans + dp[dices-1][target-i]) % mod;
                    }
                }
                dp[dices][target] = ans;
            }
        }
        return dp[d][t];
    }*/
    int solveSpace(int d, int f, int t){
        // dp[dices] --> currRow    & dp[dices-1] --> prevRow
        vector<int>prevRow(t+1,0);
        vector<int>currRow(t+1,0);
        // Analysing base cases
        prevRow[0] = 1;

        // Loop for Bottom-Up Approach --> dices (0 --> d) && target (0 --> t)
        for(int dices=1; dices<=d; dices++){
            for(int target=1; target<=t; target++){
                int ans = 0;
                for(int i=1; i<=f; i++){
                    if(target >= i){
                        ans = (ans + prevRow[target-i]) % mod;
                    }
                }
                currRow[target] = ans;
            }
            prevRow = currRow;
        }
        return prevRow[t];
    }
    int numRollsToTarget(int n, int k, int target) {
        // 1.   return solve(n,k,target);
        mod = 1e9+7;
        /* 2.
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solveMem(n,k,target,dp);
        */
        // 3.   return solveTab(n,k,target);
        return solveSpace(n,k,target);
    }
};