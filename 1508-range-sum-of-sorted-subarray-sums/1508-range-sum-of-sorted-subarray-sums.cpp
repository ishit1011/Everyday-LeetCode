class Solution {
public:
    int MOD = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr;
        arr.push_back(-1);
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                arr.push_back(sum);
            }
        }
        sort(arr.begin(),arr.end());
        int ans = 0;
        for(int i=left; i<=right; i++){
            ans = (ans + arr[i]) % MOD;
        }
        return ans;
    }
};