class Solution {
public:
    bool checkPunishment(int num, int target){
        if(target < 0 || num < target) return false;
        if(num == target) return true;
        return  checkPunishment(num/10, target - num % 10) || checkPunishment(num/100, target - num % 100) || 
                checkPunishment(num/1000, target - num % 1000);
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1; i<=n; i++){
            int sqr = i * i;
            if(checkPunishment(sqr,i)){
                ans += sqr;
            }
        }
        return ans;
    }
};