class Solution {
public:
    int findComplement(int num) {
        int cntBits = 0;
        int temp = num;
        while(num){
            cntBits++;
            num = num>>1;
        }
        return pow(2,cntBits) - temp - 1;
    }
};