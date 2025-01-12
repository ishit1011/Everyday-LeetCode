class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n == k) return true;
        if(n < k) return false;

        unordered_map<char,int> mpFreq;
        for(int i=0; i<n; i++){
            mpFreq[s[i]]++;
        }
        int oddCnt = 0;
        for(auto [x,y] : mpFreq){
            if(y % 2 != 0){
                oddCnt++;
            }
        }
        if(k < oddCnt) return false;
        return true;
    }
};