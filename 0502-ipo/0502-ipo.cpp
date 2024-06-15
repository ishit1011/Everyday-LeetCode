class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> p(n);
        for(int i=0; i<n; i++){
            p[i] = {capital[i],profits[i]};
        }
        sort(p.begin(),p.end());
        priority_queue<int> maxHp; // has only profits
        int idx = 0;

        while(k--){
            while(idx < n && p[idx].first <= w){
                maxHp.push(p[idx].second);
                idx++;
            }
            if(maxHp.empty()){
                break;
            }
            w += maxHp.top();
            maxHp.pop();
        }
        return w;
    }
};