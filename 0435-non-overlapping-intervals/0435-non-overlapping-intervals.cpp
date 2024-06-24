class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n = arr.size();

        for(int i=0; i<n; i++){
            swap(arr[i][0],arr[i][1]);
        }
        sort(arr.begin(),arr.end());
        
        int prevEnd = arr[0][0], res = 0;
        for(int i=1; i<n; i++){
            if(arr[i][1] < prevEnd){
                prevEnd = min(prevEnd,arr[i][0]);
                res++;
            }
            else{
                prevEnd = arr[i][0];
            }
        }
        return res;
    }
};