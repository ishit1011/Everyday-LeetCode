class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> setVal;
        int n = nums.size();
        for(int i=0; i<n; i++){
            setVal.insert(nums[i]);
        }
        int m = setVal.size(), l = 0, r = m-1;
        int count = 0;
        while(l <= n-m && r < n){
            unordered_map<int,int> mp;
            for(int i=l; i<=r; i++){
                mp[nums[i]]++;
            }
            if(mp.size() != m){
                r++;
            }
            else{
                count += n-r;
                l++;
                r = l+m-1;
            }
        }
        return count;
    }
};