class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0, n = arr.size();
        int i = 0;
        while(i<=n-3){
            if(arr[i] % 2 != 0 && arr[i+1] % 2 != 0 && arr[i+2] % 2 != 0){
                cout<<"x";
                return true;
            }
            i++;
        }
        return false;
    }
};