class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        map<int,int> count;
        for(int i=0; i<n; i++){
            count[hand[i]]++;
        }

        while(n--){
            for(auto [a,b] : count){
                for(int i=a; i<a+groupSize; i++){
                    if(count[i] == 0) return false;
                    count[i]--;
                    if(count[i] == 0) count.erase(i);
                }
                break;
            }
        }
        return true;
    }
};