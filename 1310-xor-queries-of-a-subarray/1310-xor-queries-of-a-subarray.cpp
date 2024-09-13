class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = queries.size();
        for(int i=0; i<n; i++){
            int i1 = queries[i][0], i2 = queries[i][1];
            int s = arr[i1];
            for(int j=i1+1; j<=i2; j++){
                s = s ^ arr[j];
            }
            ans.push_back(s);
        }
        return ans;
    }
};