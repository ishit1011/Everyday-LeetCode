class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto x : nums){
            map[x]++;
        }
        int ans = 0;
        for(auto x : map){
            int num = x.second;
            if(num == 1)return -1;
            ans += num/3;
            if(num%3 != 0)ans++;
        }
        return ans;
    }
};