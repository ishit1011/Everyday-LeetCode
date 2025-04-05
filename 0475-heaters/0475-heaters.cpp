class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        sort(houses.begin(),houses.end());
        int heaterPtr = 0, ans = 0, n = heaters.size();
        for(int i=0; i<houses.size(); i++){
            while(heaterPtr<n-1 && abs(houses[i]-heaters[heaterPtr]) >= abs(houses[i]-heaters[heaterPtr+1])){
                heaterPtr++;
            }
            ans = max(ans,abs(houses[i]-heaters[heaterPtr]));
        }
        return ans;
    }
};