class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans;
        unordered_map<int,int> ballColorMap, colorBallMap;
        
        for(int i=0; i<n; i++){
            int b = queries[i][0], color = queries[i][1];
            // ballColor exist
            if(ballColorMap.find(b) != ballColorMap.end()){
                int prevColor = ballColorMap[b];
                colorBallMap[prevColor]--;
                if(colorBallMap[prevColor] == 0) colorBallMap.erase(prevColor);
            }
            ballColorMap[b] = color;
            colorBallMap[color]++;;
            ans.push_back(colorBallMap.size());
        }
        return ans;
    }
};