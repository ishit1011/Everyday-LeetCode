class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<set<char>> poss;
        int n = s1.size();

        for (int i = 0; i < n; i++) {
            char c1 = s1[i], c2 = s2[i];

            int found1 = -1, found2 = -1;

            // Find which sets contain c1 and c2
            for (int j = 0; j < poss.size(); j++) {
                if (poss[j].count(c1)) found1 = j;
                if (poss[j].count(c2)) found2 = j;
            }

            if (found1 == -1 && found2 == -1) {
                // Neither character found, create new set
                set<char> newSet = {c1, c2};
                poss.push_back(newSet);
            } else if (found1 != -1 && found2 == -1) {
                // Only c1 found, insert c2 into its set
                poss[found1].insert(c2);
            } else if (found1 == -1 && found2 != -1) {
                // Only c2 found, insert c1 into its set
                poss[found2].insert(c1);
            } else if (found1 != found2) {
                // Both found in different sets, merge them
                poss[found1].insert(poss[found2].begin(), poss[found2].end());
                poss.erase(poss.begin() + found2);
                if (found1 > found2) swap(found1, found2); // adjust index due to erase
            }
            // If both characters are in the same set, do nothing
        }

        string ans = "";

        for (char ch : baseStr) {
            bool found = false;
            for (auto& st : poss) {
                if (st.count(ch)) {
                    ans += *st.begin(); // sets are ordered, so *begin() is smallest
                    found = true;
                    break;
                }
            }
            if (!found) ans += ch; // no equivalence found, keep original
        }

        return ans;
    }
};
