class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1;
        int num = n;
        while(n > 0){
            sum += n % 10;
            product *= n % 10;
            n = n/10;
        }
        int total = sum+product;
        if(num % total == 0){
            return true;
        }
        return false;
    }
};