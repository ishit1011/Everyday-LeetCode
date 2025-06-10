class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        for(char ch : s){
            mp[ch]++;
        }
        int maxOdd = INT_MIN, minEven = INT_MAX;
        for(auto [x,y] : mp){
            if(y % 2 == 0){
                minEven = min(minEven,y);
            }
            else{
                maxOdd = max(maxOdd,y);
            }
        }
        return maxOdd-minEven;
    }
};