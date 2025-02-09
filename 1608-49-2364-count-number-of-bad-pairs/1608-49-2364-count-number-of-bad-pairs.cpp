class Solution {
public:
    long long calcPairs(int x){
        long long ans = 0;
        for(int i=0; i<=x; i++){
            ans += i;
        }
        return ans;
    }
    long long countBadPairs(vector<int>& nums) {
        //  [ 4 1 3 3] 
        // i: 0 1 2 3 ---> 0 pairs with : (0), 1 pairs with : (1,0), 2 pairs with (2,1,0)
        int n = nums.size();
        long long totalPairs = 0;
        for(int i=0; i<n; i++){
            totalPairs += i;
        }
        // Find good pairs : [x-axis : indexes ; y-axis : value nums[]]
        unordered_map<int,int> mp;
        long long goodPairs = 0;
        for(int i=0; i<n; i++){
            mp[nums[i]-i]++;
        }
        for(auto [x,y] : mp){
            goodPairs += calcPairs(y-1);
        }
        cout<<"total : "<<totalPairs<<" good : "<<goodPairs<<endl;
        return totalPairs-goodPairs;
    }
};