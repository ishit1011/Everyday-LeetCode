class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // Brute force O(n^3)
        int cnt = 0;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            int xa = points[i][0], ya = points[i][1];
            for (int j = 0; j < n; j++) {
                if(i==j) continue;
                int xb = points[j][0], yb = points[j][1];

                
                if (xa > xb || ya < yb) continue;
                // A must be upper-left of B
                bool noInBW = true;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    int xc = points[k][0], yc = points[k][1];

                    // check if C lies inside/on rectangle [xa,xb] × [yb,ya]
                    if (xa <= xc && xc <= xb && yb <= yc && yc <= ya) {
                        noInBW = false;
                        break;
                    }
                }
                if (noInBW) cnt++;
            }
        }
        return cnt;
    }
};