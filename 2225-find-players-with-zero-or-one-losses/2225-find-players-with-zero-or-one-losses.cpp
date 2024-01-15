class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;

        int n = matches.size();
        unordered_map<int,int> lossCounter;
        unordered_map<int,int> winCounter;

        for(int i=0; i<matches.size(); i++){
            winCounter[matches[i][0]]++;
            lossCounter[matches[i][1]]++;
        }
        vector<int> lostZero;
        for(auto it=winCounter.begin(); it!=winCounter.end(); it++){
            if(it->second >= 1 && lossCounter[it->first] == 0){
                lostZero.push_back(it->first);
            }
        }
        vector<int> lostOne;
        for(auto it=lossCounter.begin(); it!=lossCounter.end(); it++){
            if(it->second == 1){
                lostOne.push_back(it->first);
            }
        }
        sort(lostOne.begin(),lostOne.end());
        sort(lostZero.begin(),lostZero.end());
        ans.push_back(lostZero);
        ans.push_back(lostOne);
        return ans;
    }
};