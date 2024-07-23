class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        map<int,int> numCnt;
        for(int i=0; i<n; i++){
            numCnt[nums[i]]++;
        }

        sort(nums.begin(),nums.end(),[&](int a,int b) {
            if(numCnt[a] == numCnt[b]){
                return a > b;
            }
            return numCnt[a] < numCnt[b];
        });
        return nums;
    }
};