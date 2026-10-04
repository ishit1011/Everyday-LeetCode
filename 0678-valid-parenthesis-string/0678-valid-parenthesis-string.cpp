class Solution {
public:
    int solve(string &s,int i,int balance,int n, vector<vector<int>> &dp){
        if(i == n) return balance;
        if(balance > n/2 || balance < 0) return balance;
        if(dp[i][balance] != -1) return dp[i][balance];

        int open = 0, closed = 0, empty = 0;
        if(s[i] == '*'){
            open = solve(s,i+1,balance+1,n,dp);
            closed = solve(s,i+1,balance-1,n,dp);
            empty = solve(s,i+1,balance,n,dp);
        }
        else if(s[i] == '('){
            open = solve(s,i+1,balance+1,n,dp);
            closed = solve(s,i+1,balance+1,n,dp);
            empty = solve(s,i+1,balance+1,n,dp);
        }
        else if(s[i] == ')'){
            open = solve(s,i+1,balance-1,n,dp);
            closed = solve(s,i+1,balance-1,n,dp);
            empty = solve(s,i+1,balance-1,n,dp);
        }

        return dp[i][balance] = (open && closed && empty);
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>((2*n)+1,-1));
        return solve(s,0,0,n,dp) == 0;
    }
};