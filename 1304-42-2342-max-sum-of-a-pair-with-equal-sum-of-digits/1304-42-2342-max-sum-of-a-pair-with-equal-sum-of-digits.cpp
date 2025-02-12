class Solution {
public:
    int getDigitSum(int n){
        int sum = 0;
        while(n > 0){
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        // can use : priority queue as well
        // vector<priority_queue<int,vector<int>, greater<int>>>
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            int digitSum = getDigitSum(nums[i]);
            mp[digitSum].push_back(nums[i]);
            if(mp[digitSum].size() > 2){
                sort(mp[digitSum].begin(), mp[digitSum].end());
                mp[digitSum].erase(mp[digitSum].begin());
            }
        }
        int ans = -1;
        for(auto [x,vec] : mp){
            if(vec.size() == 2){
                ans =  max(ans,vec[0]+vec[1]);
            }
        }
        return ans;
    }
};