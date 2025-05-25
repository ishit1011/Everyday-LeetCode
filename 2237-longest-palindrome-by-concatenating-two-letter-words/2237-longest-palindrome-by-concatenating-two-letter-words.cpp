class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;
        for (auto it : words) {
            m[it]++;
        }

        int ans = 0;
        int palin = 0;
        bool centralUsed = false;

        for (auto it : m) {
            string s1 = it.first;
            string s2 = "";
            s2 += s1[1];
            s2 += s1[0];

            if (s1 == s2) {
                ans += (m[s1] / 2) * 4;
                if (m[s1] % 2 == 1) {
                    centralUsed = true;
                }
            } else if (m.find(s2) != m.end()) {
                // It's a non-palindromic pair like "ab" and "ba"
                int pairCount = min(m[s1], m[s2]);
                ans += pairCount * 4;
                m[s1] -= pairCount;
                m[s2] -= pairCount;
            }
        }

        if (centralUsed) {
            ans += 2; // Add one palindromic string in the center
        }

        return ans;
    }
};