class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> checkArr;
        sort(arr.begin(),arr.end());

        for(int i=0; i<arr.size(); i++){
            int count = 1;
            while(i+1 < arr.size() && arr[i] == arr[i+1]){
                count++;
                i++;
            }
            checkArr.push_back(count);
        }
        sort(checkArr.begin(),checkArr.end());
        for(int i=1; i<checkArr.size(); i++){
            if(checkArr[i] == checkArr[i-1]){
                return false;
            }
        }
        return true;
    }
};