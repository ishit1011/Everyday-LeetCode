class Solution {
public:
    pair<int, int> findRowCol(int num, unordered_map<int, pair<int, int>>& posMap) {
        return posMap[num]; // Direct lookup in the map
    }

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        // Precompute the positions of each element in the matrix
        unordered_map<int, pair<int, int>> posMap;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                posMap[mat[i][j]] = {i, j};
            }
        }

        // Track row and column frequencies
        vector<int> rowFreq(m, 0), colFreq(n, 0);
        for (int i = 0; i < arr.size(); i++) {
            auto [row, col] = findRowCol(arr[i], posMap); // Lookup positions
            rowFreq[row]++;
            colFreq[col]++;
            if (rowFreq[row] == n || colFreq[col] == m) {
                return i; // Return the first index when a row/col is complete
            }
        }

        return 0;
    }
};