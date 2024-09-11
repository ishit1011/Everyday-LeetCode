class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num = start ^ goal;
        int cntOnes = 0;
        while(num != 0){
            if(num&1 == 1){
                cntOnes++;
            }
            num = num>>1;
        }
        return cntOnes;
    }
};