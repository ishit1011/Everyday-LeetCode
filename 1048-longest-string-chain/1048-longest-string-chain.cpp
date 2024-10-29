class Solution {
public:
    bool isPred(string& prev, string& curr){
        int M = prev.length(), N = curr.length();
        if(M >= N || N-M != 1){
            return false;
        }
        int i=0, j=0;
        while(i < N && j < M){
            if(prev[j] == curr[i]){
                j++;
            }
            i++;
        }
        return j==M;
    }
    static bool cmp(string &s1, string & s2){
        return s1.size() < s2.size();
    }
    int solve(vector<string>& words, int prev, int curr, vector<vector<int>> &dp){
        if(curr == words.size()){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        int takeL = 0, notTakeL = 0;
        if(prev == -1 || isPred(words[prev],words[curr])){
            takeL = 1 + solve(words,curr,curr+1,dp);
        }
        notTakeL = solve(words,prev,curr+1,dp);
        return dp[curr][prev+1] = max(notTakeL,takeL);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n = words.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(words,-1,0,dp);
    }
};