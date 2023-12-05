class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while(n > 1){
            int adder = 0;
            if(n % 2 == 0){
                adder = n/2;
            }
            else{
                adder = (n-1)/2;
            }
            ans += adder;
            n = n - adder;
        }
        return ans;
    }
};