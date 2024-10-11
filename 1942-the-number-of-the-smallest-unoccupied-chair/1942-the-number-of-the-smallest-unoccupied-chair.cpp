class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        // Add original index to keep track of friend number
        for (int i = 0; i < n; i++) {
            times[i].push_back(i);
        }

        // Sort based on arrival time
        sort(times.begin(), times.end());

        // Keep track of chair availability
        vector<int> chairsTime(n, -1);  // -1 means chair is free

        for (int i = 0; i < n; i++) {
            int arr = times[i][0];  // Arrival time
            int dep = times[i][1];  // Departure time
            int fNum = times[i][2]; // Friend's index

            // Find the first available chair
            for (int j = 0; j < n; j++) {
                // Check if the chair is free or if it's free by the time the current friend arrives
                if (chairsTime[j] == -1 || chairsTime[j] <= arr) {
                    // If this is the target friend, return the chair index
                    if (fNum == targetFriend) {
                        return j;
                    }

                    // Otherwise, assign this chair to the current friend until their departure time
                    chairsTime[j] = dep;
                    break;  // Move to the next friend after assigning a chair
                }
            }
        }
        return n;
    }
};
