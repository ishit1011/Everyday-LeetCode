class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1) return false;
        int num = n;
        while(num > 1){
            int rem = num % 3;
            if(rem == 0){
                num = num/3;
            }
            else{
                return false;
            }
        }
        return true;
    }
};