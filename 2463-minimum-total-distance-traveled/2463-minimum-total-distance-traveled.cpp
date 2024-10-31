class Solution {
public:
    long long solve(vector<int>& robot, vector<vector<int>>& factory, int i, int j, vector<vector<vector<long long>>> &dp){
        if(i >= robot.size()){
            return 0;
        }
        if(j >= factory.size()){
            return LLONG_MAX/10;
        }
        if(dp[i][j][factory[j][1]] != -1){
            return dp[i][j][factory[j][1]];
        }
        long long take = LLONG_MAX;
        if(factory[j][1] > 0){
            factory[j][1]--;
            take = abs(robot[i]-factory[j][0]) + solve(robot,factory,i+1,j,dp);
            factory[j][1]++;
        }
        long long notTake = solve(robot,factory,i,j+1,dp);
        return dp[i][j][factory[j][1]] = min(take,notTake);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        int n = robot.size(), m = factory.size();

        vector<vector<vector<long long>>> dp(n+2,vector<vector<long long>>(m+2,vector<long long>(n+2,-1)));
        return solve(robot,factory,0,0,dp);
    }
};