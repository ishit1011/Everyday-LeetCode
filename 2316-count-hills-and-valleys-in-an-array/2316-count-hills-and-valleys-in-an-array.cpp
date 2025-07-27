class Solution {
public:
    bool sameHillValley = false;
    bool checkLeftSmaller(vector<int>nums, int i){
        if(nums[i-1] < nums[i]) return true;
        if(nums[i-1] == nums[i]){
            int idx = i-2;
            sameHillValley = true;
            while(idx > 0 && nums[idx] != nums[i]){
                idx--;
            }
            if(idx > 0){
                if(nums[idx] < nums[i])return true;
                else return false;
            }
            else return false;
        }
        return false;
    }
    bool checkRightSmaller(vector<int>nums, int i){
        int n = nums.size();
        if(nums[i+1] < nums[i]){
            return true;
        }
        if(nums[i+1] == nums[i]){
            int idx = i+2;
            sameHillValley = true;
            while(idx < n && nums[idx] != nums[i]){
                idx++;
            }
            if(idx < n){
                if(nums[idx] < nums[i])return true;
                else return false;
            }
            else return false;
        }
        return false;
    }
    int countHillValley(vector<int>& nums) {
        int hills = 0, valley = 0;
        int n = nums.size();
        for(int i=1; i<n-1; i++){
            if(sameHillValley == true){
                sameHillValley = false;
                continue;
            }
            bool rightSmall = checkRightSmaller(nums,i);
            bool leftSmall = checkLeftSmaller(nums,i);
            if(leftSmall && rightSmall) hills++;
            if(!leftSmall && !rightSmall) valley++;
            cout<<"i : "<<i<<" hills: "<<hills<<" valleys: "<<valley<<endl;
        }
        return hills+valley;
    }
};