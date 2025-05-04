class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string, int> map;
        int cnt = 0;

        for (auto& d : dominoes) {
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            string key = to_string(a) + "," + to_string(b);

            cnt += map[key];
            map[key]++;
        }

        return cnt;
    }
};