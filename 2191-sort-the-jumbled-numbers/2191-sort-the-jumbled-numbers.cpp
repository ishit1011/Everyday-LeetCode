class Solution {
public:
    int numMap(vector<int>& mapping, int num){
        vector<int> tempNum;
        while(num != 0){
            int digit = num % 10;
            tempNum.push_back(digit);
            num = num/10;
        }
        for(int i=0; i<tempNum.size(); i++){
            int x = tempNum[i];
            tempNum[i] = mapping[x];
        }
        int number = 0;
        for(int i=0; i<tempNum.size(); i++){
            number += tempNum[i] * pow(10,i);
        }
        return number;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> mp(n);
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                mp[i] = {mapping[0],i};
            }
            else{
                int mapped = numMap(mapping, nums[i]);
                mp[i] = {mapped,i};
            }
        }

        // sorts in ascending : if 2 elements have same 1st num ==> sorts accroding to INDEX
        sort(mp.begin(),mp.end());

        vector<int> ans;
        for(auto it : mp){
            ans.push_back(nums[it.second]);
        }
        return ans;
    }
};