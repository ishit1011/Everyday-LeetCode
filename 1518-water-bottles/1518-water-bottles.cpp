class Solution {
public:
    int numWaterBottles(int nBottles, int ex) {
        // 15 --> 15/4 = 3 full + 15%4 =  3 empty ---> 6/4 = 1 + 6%4 = 2
        int currEmpty = (nBottles/ex) + (nBottles%ex);
        int ans = nBottles + (nBottles/ex);
        while(currEmpty >= ex){
            nBottles = currEmpty;
            ans += (nBottles/ex);
            currEmpty = (nBottles/ex) + (nBottles%ex);
        }
        return ans;
    }
};