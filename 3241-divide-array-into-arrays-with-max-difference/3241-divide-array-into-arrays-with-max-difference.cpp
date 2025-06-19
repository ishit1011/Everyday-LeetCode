class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0; i<n-2; i+=3){
            int first = nums[i], last = nums[i+2];
            vector<int> row;
            if(last-first > k){
                ans.clear();
                return ans;
            }
            else{
                for(int j=i; j<=i+2; j++){
                    row.push_back(nums[j]);
                }
                ans.push_back(row);
            }
        }
        return ans;
    }
};