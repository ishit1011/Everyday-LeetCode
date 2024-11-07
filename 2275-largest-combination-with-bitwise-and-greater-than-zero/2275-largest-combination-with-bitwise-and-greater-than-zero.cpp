class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        vector<int> idxBitCnts(24,0);
        for(int i=0; i<24; i++){
            for(int num : candidates){
                if((num & (1<<i)) != 0){
                    idxBitCnts[i]++;
                }
            }
        }
        int ans = 0;
        for(int i=0; i<24; i++){
            ans = max(ans,idxBitCnts[i]);
        }
        return ans;
    }
};