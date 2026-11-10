class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> reachCost(n+1,0);

        reachCost[0] = 0;

        for(int i=0; i<n; i++){
            int step = INT_MAX;
            // only way to reach here is +1 step
            if(i == 0){
                step = 1 + costs[i];
            }
            // to reach here : way1 = 0 ---> 2, way2 = 1 --> 2
            else if(i == 1){
                step = costs[i] + min(4, 1 + reachCost[i]);
            }
            // to reach here : way1 = 0 ---> 3, way2 = 1 --> 3, way3 = 2 ---> 3
            else{
                step = costs[i] + min({1 + reachCost[i], 4 + reachCost[i-1], 9 + reachCost[i-2]});
            }
            reachCost[i+1] = step;
        }

        return reachCost[n];
    }
};