class Solution {
public:
    /*          DP - TLE > O(n^2)
    int solve(vector<int> arr,int i,int parity, int prev){
        int takeLen = 0, notTakeLen = 0;
        if(i == arr.size()){
            return 0;
        }
        int curr = arr[i];
        // First element assessed
        if(parity == -1 && prev == -1){
            takeLen = solve(arr,i+1,parity,curr) + 1;
            notTakeLen = solve(arr,i+1,parity,prev);
        }
        // Second element assessed
        if(parity == -1 && prev != -1){
            int p = (curr + prev) % 2;
            takeLen = solve(arr,i+1,p,curr) + 1;
            notTakeLen = solve(arr,i+1,parity,prev);
        }
        if(parity != -1){
            int p = (curr + prev) % 2;
            if(p == parity){
                takeLen = solve(arr,i+1,p,curr) + 1;
                notTakeLen = solve(arr,i+1,parity,prev);
            }
            else{
                notTakeLen = solve(arr,i+1,parity,prev);
            }
        }
        return max(takeLen, notTakeLen);
    }
    */
    int maximumLength(vector<int>& nums) {
        // return solve(nums,0,-1,-1);
        int res = 0;
        vector<vector<int>> patterns = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        for (auto& pattern : patterns) {
            int cnt = 0;
            for (int num : nums) {
                if (num % 2 == pattern[cnt % 2]) {
                    cnt++;
                }
            }
            res = max(res, cnt);
        }
        return res;
    }
};