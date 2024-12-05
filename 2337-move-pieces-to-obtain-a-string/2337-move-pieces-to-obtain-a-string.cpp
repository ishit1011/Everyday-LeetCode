class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;

        while (i < n || j < n) {
            // Skip underscores in start
            while (i < n && start[i] == '_') {
                i++;
            }
            // Skip underscores in target
            while (j < n && target[j] == '_') {
                j++;
            }
            // If one string is exhausted, both should be exhausted
            if (i == n || j == n) {
                return i == n && j == n;
            }

            // Check if the pieces match and follow movement rules
            if (start[i] != target[j] ||
                (start[i] == 'L' && i < j) ||
                (start[i] == 'R' && i > j))
                return false;

            i++;
            j++;
        }
        return true;
    }
};