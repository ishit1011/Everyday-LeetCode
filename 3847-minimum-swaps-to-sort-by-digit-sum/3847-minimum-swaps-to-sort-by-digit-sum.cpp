class Solution {
public:
    int sumDigit(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> sortedVals; // {digitSum, value}
        for (int num : nums) {
            sortedVals.push_back({sumDigit(num), num});
        }

        // Sort based on digitSum, then value
        sort(sortedVals.begin(), sortedVals.end());

        // Map value to its position in the sorted array
        unordered_map<int, int> valToSortedIndex;
        for (int i = 0; i < n; ++i) {
            valToSortedIndex[sortedVals[i].second] = i;
        }

        // Build pos[]: current_index → target_index in sorted array
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[i] = valToSortedIndex[nums[i]];
        }

        // Detect cycles
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || pos[i] == i) continue;

            int cycle_len = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = pos[j];
                cycle_len++;
            }

            swaps += (cycle_len - 1);
        }

        return swaps;
    }
};