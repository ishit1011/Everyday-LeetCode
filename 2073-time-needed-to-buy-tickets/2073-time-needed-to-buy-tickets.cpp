class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0;
        int key = tickets[k];
        for(int i=0; i<tickets.size(); i++){
            // Elements to left of "k"
            if(i <= k){
                count += min(tickets[i],key);
            }
            // Elements right of "k"
            else{
                count += min(tickets[i],key-1);
            }
            cout<<count<<" ";
        }
        return count;
    }
};