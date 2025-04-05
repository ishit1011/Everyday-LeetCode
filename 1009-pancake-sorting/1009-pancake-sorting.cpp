class Solution {
public:
    void flipArr(int s, int e, vector<int>& arr){
        while(s<=e){
            swap(arr[s],arr[e]);
            s++;
            e--;
        }
        return;
    }
    int findIdx(vector<int> &arr, int size){
        int maxEle = INT_MIN, idx = 0;
        for(int i=0; i<=size; i++){
            if(arr[i] > maxEle){
                idx = i;
                maxEle = arr[i];
            }
        }
        return idx;
    }
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        int j = n-1;
        while(j >= 0){
            // find max element location
             int maxIdx = findIdx(arr,j);
            // unsorted
            flipArr(0,maxIdx,arr);
            ans.push_back(maxIdx+1);
            flipArr(0,j,arr);
            ans.push_back(j+1);
            j--;
        }
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        return ans;
    }
};