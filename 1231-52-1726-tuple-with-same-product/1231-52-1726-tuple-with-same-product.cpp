class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        map<int,int> prodMp;
        int ans = 0;
        // 8 * cnt : because (a,b) & (c,d) can be rearranged into 8 ways
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans += 8 * prodMp[nums[i]*nums[j]];
                prodMp[nums[i] * nums[j]]++;
            }
        }
        return ans;
    }
};