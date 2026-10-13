class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> posNums;
        int n = nums.size();
        long long ans = 0;
        for(int i=0; i<n; i++){
            posNums.push_back(abs(nums[i]));
        }
        int cnt = (n/2);
        sort(posNums.begin(),posNums.end());
        reverse(posNums.begin(),posNums.end());
        for(int i=0; i<n; i++){
            if(n % 2 == 0){
                if(i < n/2) ans += pow(posNums[i],2);
                else ans -= pow(posNums[i],2);
            }
            else{
                if(i <= n/2) ans += pow(posNums[i],2);
                else ans -= pow(posNums[i],2);
            }
            
        }
        return ans;
    }
};