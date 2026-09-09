class Solution {
public:
    long long countCommas(long long n) {
        long long cntDigits = 0;
        long long m = n;
        while(n > 0){
            n /= 10;
            cntDigits++;
        }
        
        long long commas = (cntDigits % 3 != 0) ? cntDigits / 3 : (cntDigits / 3) - 1;
        if(cntDigits < 4){
            return 0;
        }
        else if(cntDigits >= 4 && cntDigits <= 6){
            return (m-999) * commas;
        }
        else if(cntDigits >= 7 && cntDigits <= 9){
            return (m-999999) * commas + 999000 * (commas-1);
        }
        else if(cntDigits >= 10 && cntDigits <= 12){
            return (m-999999999) * commas + 999000000 * (commas-1) + 999000 * (commas-2);
        }
        else if(cntDigits >= 13 && cntDigits <= 15){
            return (m-999999999999) * commas + 999000000000 * (commas-1) + 999000000 * (commas-2) + 999000 * (commas-3);
        }
        else if(cntDigits >= 16 && cntDigits <= 18){
            return (m-999999999999999) * commas + 999000000000000 * (commas-1) + 999000000000 * (commas-2) + 999000000 * (commas-3) + 999000 * (commas-4);
        }
        return 0;
    }
};