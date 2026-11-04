class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // [1,10,2,9]
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int mid = 0;
        if(n == 2){
            mid = (nums[0] + nums[1]) / 2;
        }
        else if(n % 2 == 0){
            mid = (nums[n/2] + nums[(n/2) - 1]) / 2;
        }
        else if(n % 2 != 0){
            mid = nums[n/2];
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += abs(nums[i]-mid);
        }

        return ans;
    }
};