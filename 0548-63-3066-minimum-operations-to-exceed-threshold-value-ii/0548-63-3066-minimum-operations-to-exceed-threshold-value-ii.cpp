class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<long long,vector<long long>,greater<long long>> minHp;

        for(int i=0; i<n; i++){
            minHp.push(nums[i]);
        }
        int steps = 0;
        while(minHp.top() < k){
            long long x = minHp.top();
            minHp.pop();
            long long y = minHp.top();
            minHp.pop();
            minHp.push(min(x, y) * 2 + max(x, y));
            steps++;
        }
        return steps;
    }
};