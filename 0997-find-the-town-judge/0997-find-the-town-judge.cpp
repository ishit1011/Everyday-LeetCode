class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusted(n+1,0);
        vector<int> trusting(n+1,0);
        for(auto relation : trust){
            trusting[relation[0]]++;
            trusted[relation[1]]++;
        }

        for(int i=1; i<=n; i++){
            if(trusting[i] == 0 && trusted[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};