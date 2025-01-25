class Solution {
public:
    vector<pair<int, int>> dir = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}, {-1, -1}, {-1, +1}, {+1, -1}, {+1, +1}};

bool isSafe(int i, int j, vector<vector<int>>& grid, int n, vector<vector<bool>>& visited) {
    return (i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == 0 && !visited[i][j]);
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if (grid[0][0] == 1) return -1; // Starting point is blocked
    int n = grid.size();

    // Special case for 1x1 grid
    if (n == 1 && grid[0][0] == 0) return 1;

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    q.push({0, 0});
    visited[0][0] = true;

    int cntSteps = 0;

    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            pair<int, int> ele = q.front();
            q.pop();

            // Check if we reached the bottom-right corner
            if (ele.first == n - 1 && ele.second == n - 1) {
                return cntSteps + 1; // Increment step count for the last step
            }

            // Explore all 8 directions
            for (int i = 0; i < 8; i++) {
                int newX = dir[i].first + ele.first;
                int newY = dir[i].second + ele.second;
                if (isSafe(newX, newY, grid, n, visited)) {
                    q.push({newX, newY});
                    visited[newX][newY] = true;
                }
            }
        }
        cntSteps++; // Increment after processing all nodes at the current level
    }

    return -1; // No path exists
}

};