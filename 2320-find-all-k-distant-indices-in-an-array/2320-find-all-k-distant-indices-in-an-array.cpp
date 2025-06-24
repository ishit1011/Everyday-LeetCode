class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();
        vector<int> idxs;
        for(int i=0; i<n; i++){
            if(nums[i] == key){
                idxs.push_back(i);
            }
        }
        sort(idxs.begin(),idxs.end());
        for(int i=0; i<n; i++){
            for(int j=0; j<idxs.size(); j++){
                if(abs(i-idxs[j]) <= k){
                    ans.push_back(i);
                    break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};