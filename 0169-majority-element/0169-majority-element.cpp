class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size()/2;
        sort(nums.begin(),nums.end());
        return nums[n];
    }
};

// If a number is appearing more than half of size of array,
// then it will definitely be present at the middle of the array after sorting