class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int res = 0;
        int upCount = 1, downCount = 0, candiesGiven = 1, peak = 0;
        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                upCount++;
                downCount = 0;
                candiesGiven += upCount;
                peak = upCount;
            }
            if(ratings[i] == ratings[i-1]){
                downCount = 0;
                peak = 0;
                upCount = 1;
                candiesGiven++;
            }
            if(ratings[i] < ratings[i-1]){
                downCount++;;
                upCount = 1;
                candiesGiven += downCount;
                if(downCount >= peak){
                    candiesGiven++;
                }
            }
        }
        return candiesGiven;
    }
};