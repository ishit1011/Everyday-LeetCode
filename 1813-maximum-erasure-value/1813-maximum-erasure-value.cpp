class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        // for(int i=0; i<n; i++){
        //     unordered_map<int,int> mp;
        //     int j = i;
        //     int temp = 0;
        //     while(j<n && mp[nums[j]] < 1){
        //         mp[nums[j]]++;
        //         temp += nums[j];
        //         j++;
        //     }
        //     maxSum = max(maxSum,temp);
        // }
        int l = 0, tempSum = 0, maxSum = 0;
        unordered_set<int> seen;

        for (int r = 0; r < nums.size(); ++r) {
            while (seen.count(nums[r])) {
                seen.erase(nums[l]);
                tempSum -= nums[l];
                l++;
            }
            seen.insert(nums[r]);
            tempSum += nums[r];
            maxSum = max(maxSum, tempSum);
        }
        return maxSum;
    }
};