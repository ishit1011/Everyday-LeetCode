class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();

        vector<int> prefixXors(n);
        prefixXors[0] = nums[0];
        
        for(int i=1; i<n; i++){
            prefixXors[i] = prefixXors[i-1] ^ nums[i];
        }
        int maxDecimal = pow(2,maximumBit)-1;
        vector<int> ans(n,maxDecimal);
    
        for (int i = 0; i < n; i++) {
            ans[n - i - 1] = maxDecimal ^ prefixXors[i];
        }
        return ans;
    }
};