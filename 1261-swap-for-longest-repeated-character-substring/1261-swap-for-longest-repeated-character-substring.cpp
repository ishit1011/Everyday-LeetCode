class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        unordered_map<char, int> mp;
        for (char c : text) {
            mp[c]++;
        }

        int ans = 0;
        int i = 0;

        while (i < n) {
            // Count continuous same chars
            int j = i;
            while (j < n && text[j] == text[i]) j++;
            int len1 = j - i;

            // Check for split group like: aaaXaaa
            int k = j + 1;
            while (k < n && text[k] == text[i]) k++;
            int len2 = k - (j + 1);

            int total = len1 + len2;

            // If more occurrences of this char exist, we can add one via swap
            if (mp[text[i]] > total)
                ans = max(ans, total + 1);
            else
                ans = max(ans, total);

            // Also compare against the current continuous group
            if (mp[text[i]] > len1)
                ans = max(ans, len1 + 1);
            else
                ans = max(ans, len1);

            i = j;
        }

        return ans;
    }
};
