class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        vector<int> ans(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHp;
        for(int i=0; i<n; i++){
            minHp.push({nums[i],i});
        }
        while(k--){
            auto smallest = minHp.top();
            minHp.pop();
            int smallVal = smallest.first, smallIdx = smallest.second;
            smallVal *= multiplier;
            minHp.push({smallVal,smallIdx});
        } 
        while(!minHp.empty()){
            auto ele = minHp.top();
            int val = ele.first, idx = ele.second;
            ans[idx] = val;
            minHp.pop();
        }
        return ans;
    }
};