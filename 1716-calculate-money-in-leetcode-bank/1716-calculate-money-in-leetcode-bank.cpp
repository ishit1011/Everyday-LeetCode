class Solution {
public:
    int totalMoney(int n) {
        int total = 0;
        int weekCount = 0, dailySum = 0;

        for(int i=1; i<=n; i++){
            if(i % 7 == 1){
                weekCount++;
                dailySum = weekCount;
            }
            else{
                dailySum++;
            }
            total += dailySum;
        }
        return total;
    }
};