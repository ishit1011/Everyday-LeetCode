class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        set<int> st;
        for(int i=0; i<n; i++){
            if(st.count(arr[i]*2) || (arr[i]%2 == 0 && st.count(arr[i]/2))){
                return true;
            }
            st.insert(arr[i]);
        }
        return false;
    }
};