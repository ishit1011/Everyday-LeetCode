class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp; // last occurence
        for(int i=0; i<n; i++){
            mp[nums[i]] = i;
        }
        for(int i=0; i<n; i++){
            int diff = target-nums[i];
            cout<<"diff : "<<diff<<endl;
            if(mp.find(diff) != mp.end()){
                if(mp[diff] != i){
                    return {i,mp[diff]};   
                }
            }
        }
        return {0,0};
    }
};