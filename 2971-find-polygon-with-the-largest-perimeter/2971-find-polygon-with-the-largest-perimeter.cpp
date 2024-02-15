class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=n-1; i>=0; i--){
            long long a = nums[i];
            long long sumOfRest = 0;
            for(int j=i-1; j>=0; j--){
                sumOfRest += nums[j];
            }
            if(sumOfRest > a){
                return sumOfRest + a;
            }
        }
        return -1;   
    }
};