class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        for(int i=0; i<n; i++){
            if(stk.empty() || stk.top() < arr[i]){
                stk.push(arr[i]);
            }
            else{
                int maxEle = stk.top();
                while(!stk.empty() && stk.top() > arr[i]){
                    stk.pop();
                }
                stk.push(maxEle);
            }
        }
        return stk.size();
    }
};