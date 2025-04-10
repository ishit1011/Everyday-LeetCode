class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int minima = nums[0];
        set<int> numSet;
        for(int i=0; i<nums.size(); i++){
            numSet.insert(nums[i]);
        }
        if(minima < k){
            return -1;
        }
        // cout<<numSet.size();
        return minima == k ? numSet.size()-1 : numSet.size();
    }
};