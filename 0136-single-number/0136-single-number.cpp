class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> count;
        for(int i=0; i<nums.size(); i++){
            count[nums[i]]++;
        }
        for(auto it : count){
            if(it.second == 1){
                return it.first;
            }
        }
        return -1;
    }
};