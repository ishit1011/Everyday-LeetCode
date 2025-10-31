class Solution {
public:
    int getNumSmlMid(int num, vector<int> &nums){
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= num){
                cnt++;
            }
        }
        return cnt;
    }
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int l = 1, r = n;
        while(l < r){
            int mid = (l + r)/2;
            int countEle = getNumSmlMid(mid,nums);
            if(countEle <= mid){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return l;
    }
};