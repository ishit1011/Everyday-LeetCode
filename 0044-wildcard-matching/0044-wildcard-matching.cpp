class Solution {
public:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>>& dp){
        if(i<0 && j<0){ // string & pattern both OVER
            return true;
        }
        if(i>=0 && j<0){ // string : LEFT & pattern : OVER
            return false;
        }
        if(i<0 && j>=0){ // string : OVER & pattern : LEFT
            // Check if remaining elements of pattern are all "*" only 
            while(j >= 0){
                if(p[j] != '*'){
                    return false;
                }
                j--;
            }
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(p[j] == '*'){
            return dp[i][j] = (solve(s,p,i-1,j,dp) || solve(s,p,i,j-1,dp));
        }
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = solve(s,p,i-1,j-1,dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(s,p,n-1,m-1,dp);
    }
};