class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        int maxLucky = INT_MIN;
        for(auto [x,y] : mp){
            if(y == x){
                maxLucky = max(maxLucky,x);
            }
        }
        return maxLucky == INT_MIN ? -1 : maxLucky;
    }
};