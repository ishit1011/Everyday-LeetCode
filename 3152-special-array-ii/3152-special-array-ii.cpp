class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefixChk(n,0);
        for(int i=1; i<n; i++){
            prefixChk[i] = prefixChk[i-1];
            if((nums[i] % 2 == 0 && nums[i-1] % 2 == 0) || (nums[i] % 2 != 0 && nums[i-1] % 2 != 0)){
                prefixChk[i]++;
            }
        }
        int m = queries.size();
        vector<bool> ans;
        for(int i=0; i<m; i++){
            int fromIdx = queries[i][0], toIdx = queries[i][1];
            int specialCnt = prefixChk[toIdx];
            if(fromIdx > 0){
                specialCnt -= prefixChk[fromIdx];
            }
            ans.push_back(specialCnt == 0);
        }
        return ans;
    }
};