class Solution {
public:
    bool compareSwap(int i, int j){
        string a = to_string(i);
        string b = to_string(j);
        if(a+b > b+a){
            return true;
        }
        return false;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        // 1. sort the array according to comparing every pair of numbers [10,2] : 102 < 210
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(!compareSwap(nums[i],nums[j])){
                    swap(nums[i],nums[j]);
                }
            }
        }
        // 2. Add to the answer
        string ans = "";
        for(int x : nums){
            string str = to_string(x);
            ans += str;
        }
        if(ans[0] == '0' && ans[ans.length()-1] == '0'){
            return "0";
        }
        return ans;
    }
};