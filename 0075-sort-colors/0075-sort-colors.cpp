class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        nums.clear();
        int m = mp.size();
        for(auto [x,y] : mp){
            for(int i=0; i<y; i++){
                nums.push_back(x);
            }
        }
    }
};