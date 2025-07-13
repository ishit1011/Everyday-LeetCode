class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size(), m = trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int j = 0, i = 0, ans = 0;
        while(j<m && i<n){
            if(trainers[j] >= players[i]){
                ans++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};