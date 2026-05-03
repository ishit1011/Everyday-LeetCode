class Solution {
public:
    vector<int> fc(vector<int> &nums, int n){
        vector<int> closest;
        for(int i=0; i<n; i++){
            if(i == 0) closest.push_back(1);
            else if(i == n-1) closest.push_back(n-2);
            else{
                if(abs(nums[i] - nums[i-1]) > abs(nums[i] - nums[i+1])) closest.push_back(i+1);
                else closest.push_back(i-1);
            }
        }
        return closest;
    }
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(); 
        int m = queries.size();

        vector<int> closest = fc(nums,n);

        vector<int> forwardCost(n,0);
        for(int i=1; i<n; i++){
            if(closest[i-1] == i) forwardCost[i] = forwardCost[i-1] + 1;
            else{
                forwardCost[i] = forwardCost[i-1] + abs(nums[i]-nums[i-1]);
            }
        }

        vector<int> backwardCost(n,0);
        for(int i=n-2; i>=0; i--){
            if(closest[i+1] == i) backwardCost[i] = backwardCost[i+1] + 1;
            else backwardCost[i] = backwardCost[i+1] + abs(nums[i+1]-nums[i]);
        }

        vector<int> ans;
        for(int i=0; i<m; i++){
            int l = queries[i][0], r = queries[i][1];
            if(l > r) ans.push_back(backwardCost[r] - backwardCost[l]);
            else ans.push_back(forwardCost[r] - forwardCost[l]);
        }
        return ans;
    }
};