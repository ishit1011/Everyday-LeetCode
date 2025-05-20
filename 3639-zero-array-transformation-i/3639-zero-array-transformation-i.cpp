class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        // Difference array : Updating a subset in an array with a number to convert array into something else 
        // Multiple Range Queries with Efficiency Constraints:
        vector<int> diffArr(n+1,0);
        vector<int> prefSum(n,0);

        for(int i=0; i<queries.size(); i++){
            int s = queries[i][0], e = queries[i][1];
            diffArr[s] += 1;
            diffArr[e+1] -= 1; 
        }
        cout<<"diff array : "<<endl;
        for(int i=0; i<n; i++){
            cout<<diffArr[i]<<" ";
        }
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += diffArr[i];
            prefSum[i] = sum;
        }
        cout<<"\nprefix array : "<<endl;
        for(int i=0; i<n; i++){
            if(prefSum[i] < nums[i]){
                return false;
            }
            // cout<<prefSum[i]<<" ";
        }
        return true;
    }
};