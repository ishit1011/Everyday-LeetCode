class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int> distinct;
        int n = nums.size();
        for(int i=0; i<n; i++){
            distinct.insert(nums[i]);
        }
        vector<int> ans;
        auto it = distinct.rbegin();
        while(k-- && it != distinct.rend()){
            ans.push_back(*it);
            ++it;
        }
        return ans;
    }
};