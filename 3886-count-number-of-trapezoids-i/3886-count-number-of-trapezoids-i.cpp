class Solution {
public:
    long long MOD = 1000000007;
    int countTrapezoids(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
});
        unordered_map<int,int> yLinesMp;
        int n = points.size();
        int i = 0;
        while(i < n){
            int sameLinePts = 1;
            int currY = points[i][1];
            while(i+1 < n && points[i+1][1] == currY){
                sameLinePts++;
                i++;
            }
            int lines = 0;
            for(int k=sameLinePts-1; k>0; k--){
                lines += k;
            }
            if(lines > 0){
                yLinesMp.insert({currY,lines});
            }
            i++;
        }
        if(yLinesMp.size() == 1) return 0;
        long long totalLines = 0;
        for(auto [a,b] : yLinesMp){
            totalLines += b;
        }
        long long trapezoids = 0;
        for(auto [a,b] : yLinesMp){
            trapezoids = (trapezoids + (1LL * (totalLines - b) * b) % MOD) % MOD;
            totalLines -= b;
        }
        return (int)trapezoids;
    }
};