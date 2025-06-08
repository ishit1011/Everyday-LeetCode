class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int curr = 1;
        while (ans.size() < n) {
            // Add the current number to the result
            ans.push_back(curr);

            // Try to append a zero to the current number (move to the next level)
            if (curr * 10 <= n) {
                curr *= 10;
            }
            // If not possible, increment the current number
            else {
                // If the current number is divisible by 10 or exceeds n, backtrack
                while (curr % 10 == 9 || curr + 1 > n) {
                    curr /= 10;
                }
                curr++;
            }
        }
        return ans;
    }
};
