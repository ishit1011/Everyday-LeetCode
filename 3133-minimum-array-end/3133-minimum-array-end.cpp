class Solution {
public:
    long long minEnd(int n, int x) {
        long long lastEle = x;
        n = n-1;
        while(n--){
            lastEle = (lastEle+1) | x;
        }
        return lastEle;
    }
};