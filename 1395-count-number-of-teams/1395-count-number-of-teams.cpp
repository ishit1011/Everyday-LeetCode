class Solution {
public:
    int solveInc(vector<int>& rating, int idx, int cnt, vector<vector<int>>& dp){
        if(cnt == 3) return 1;
        if(dp[idx][cnt] != -1) return dp[idx][cnt];
        int ans = 0;
        for(int i=idx+1; i<rating.size(); i++){
            if(rating[idx] <= rating[i]) continue;
            ans += solveInc(rating, i, cnt+1, dp);
        }
        return dp[idx][cnt] = ans;
    }
    int solveDec(vector<int>& rating, int idx, int cnt, vector<vector<int>>& dp){
        if(cnt == 3) return 1;
        if(dp[idx][cnt] != -1) return dp[idx][cnt];
        int ans = 0;
        for(int i=idx+1; i<rating.size(); i++){
            if(rating[idx] >= rating[i]) continue;
            ans += solveDec(rating, i, cnt+1, dp);
        }
        return dp[idx][cnt] = ans;
    }
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int cnt = 1, res = 0;
        vector<vector<int>> dpI(1000, vector<int>(3,-1));
        vector<vector<int>> dpD(1000, vector<int>(3,-1));
        for(int i=0; i<n; i++){
            res += solveInc(rating, i, cnt, dpI);
            res += solveDec(rating, i, cnt, dpD);
        }
        return res;
    }
};