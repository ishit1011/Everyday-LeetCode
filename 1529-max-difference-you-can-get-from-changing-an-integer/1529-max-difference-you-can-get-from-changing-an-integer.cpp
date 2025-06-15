class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int maxNum = getMax(s);
        int minNum = getMin(s);
        return maxNum - minNum;
    }

private:
    int getMax(string s) {
        // Replace the first digit that's not '9' with '9'
        for (char c : s) {
            if (c != '9') {
                for (char& ch : s) {
                    if (ch == c) ch = '9';
                }
                break;
            }
        }
        return stoi(s);
    }

    int getMin(string s) {
        // If the first digit is not '1', replace all its occurrences with '1'
        if (s[0] != '1') {
            char c = s[0];
            for (char& ch : s) {
                if (ch == c) ch = '1';
            }
        } else {
            // Else, find the first digit ≠ '0' and ≠ '1' and replace with '0'
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    char c = s[i];
                    for (char& ch : s) {
                        if (ch == c) ch = '0';
                    }
                    break;
                }
            }
        }
        return stoi(s);
    }
};
