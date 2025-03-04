class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            // Check if this power should be used twice
            if (n % 3 == 2) return false;

            // Divide n by 3 to move to the next greater power
            n /= 3;
        }
        return true;
    }
};