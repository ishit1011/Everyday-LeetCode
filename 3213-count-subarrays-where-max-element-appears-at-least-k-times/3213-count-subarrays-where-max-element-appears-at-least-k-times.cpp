class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEle = 0;
        for (int i = 0; i < n; i++) {
            maxEle = max(maxEle, nums[i]);
        }

        long long subArrCnt = 0;
        int l = 0, count = 0;

        for (int r = 0; r < n; r++) {
            if (nums[r] == maxEle) {
                count++;
            }

            while (count >= k) {
                if (nums[l] == maxEle) {
                    count--;
                }
                l++;
            }

            subArrCnt += l;
        }

        return subArrCnt;
    }
};
