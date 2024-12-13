class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<n; i++){
            pq.push({nums[i],i});
        }
        vector<bool> isMarked(n,false);
        long long score = 0;
        while(!pq.empty()){
            int smallestEle = pq.top().first;
            int eleIdx = pq.top().second;
            pq.pop();
            if(isMarked[eleIdx] == false){
                score += smallestEle;
                if(eleIdx-1 >= 0){
                    isMarked[eleIdx-1] = true;
                }
                if(eleIdx+1 < n){
                    isMarked[eleIdx+1] = true;
                }
            }
        }
        return score;
    }
};