class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int p = 0;
        int num = prices[0];
        for(int i=1; i<n; i++){
            p = max(p,prices[i]-num);
            num = min(prices[i],num);
        }
        return p;
    }
};