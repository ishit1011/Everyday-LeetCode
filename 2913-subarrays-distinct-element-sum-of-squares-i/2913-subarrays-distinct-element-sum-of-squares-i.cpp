class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            set<int> distinct;
            for(int j=i; j<n; j++){
                distinct.insert(nums[j]);
                ans += pow(distinct.size(),2);
            }
            cout<<endl;
        }
        return ans;
    }
};