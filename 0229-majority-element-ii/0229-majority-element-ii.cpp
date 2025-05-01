class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        } 
        vector<int> ans;
        for(auto [x,y] : mp){
            if(y > n/3){
                ans.push_back(x);
            }
        }
        return ans;
    }
};