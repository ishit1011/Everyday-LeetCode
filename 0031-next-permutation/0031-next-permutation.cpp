class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int brkPt = -1;
        int val = 0;

        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                brkPt = i+1;
                val = i;
                break;
            }
        }
        
        if(brkPt != -1){
            for(int i=n-1; i>=brkPt; i--){
                if(nums[i] > nums[val]){
                    swap(nums[i],nums[val]);
                    break;
                }
            }
            reverse(nums.begin()+brkPt,nums.end());
        }
        else{
            reverse(nums.begin(),nums.end());
        }
        
    }
};