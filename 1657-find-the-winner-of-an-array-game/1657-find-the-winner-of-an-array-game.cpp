class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxElement = arr[0];
        for(int i=1; i<arr.size(); i++){
            maxElement = max(maxElement,arr[i]);
        }

        int curr = arr[0];
        int winStreak = 0;
        for(int i=1; i<arr.size(); i++){
            int opponent = arr[i];
            if(curr > opponent && winStreak < k){
                winStreak++;
            }
            if(curr < opponent && winStreak < k){
                curr = opponent;
                winStreak = 1;
            }
            if(curr == maxElement || winStreak == k){
                return curr;
            }
        }
        return -1;
    }
};