class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // METHOD - 1 (TLE)
        // for(int j=0; j<k; j++){
        //     for(int i=n-1; i>0 ; i--){
        //         swap(nums[i],nums[i-1]);
        //     }
        // }

        // METHOD - 2
        k = k % n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());

    }
};