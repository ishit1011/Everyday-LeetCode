class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int lastIdx = n-1;
        unordered_map<int,int> freqMp;
        for(int i=n-1; i>=0; i--){
            freqMp[nums[i]]++;
            if(freqMp[nums[i]] > 1){
                lastIdx = i;
                break;
            }
            else{
                lastIdx--;
            }
        }
        int sizeDelt = lastIdx+1;
        return sizeDelt % 3 == 0 ? sizeDelt/3 : sizeDelt/3 + 1;
    }
};