class Solution {
    public int addDigits(int num) {
        int n = num;
        int countDigits = 0;
        while (num > 0) {
            num /= 10;
            countDigits++;
        }
        while (countDigits > 1) {
            countDigits = 0;
            int sum = 0;
            while (n > 0) {
                int lastDigit = n % 10;
                n /= 10;
                sum += lastDigit;
                countDigits++;
            }
            n = sum;
            if (countDigits == 1) {
                return n;
            }
        }
        return n;
    }
}