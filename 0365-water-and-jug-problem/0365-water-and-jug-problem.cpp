class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        // BFS
        if(x + y == target || x == target || y == target){
            return true;
        }
        if(x+y < target){
            return false;
        }
        queue<int> q;
        int jugsCombinedMax = x + y;
        vector<bool> valVis(jugsCombinedMax+1,false);
        q.push(0);
        valVis[0] = true;
        vector<int> options{x,-x,y,-y};

        while(!q.empty()){
            int num = q.front();
            q.pop();
            if(num == target){
                return true;
            }   
            for(int i=0; i<4; i++){
                int curr = num + options[i];
                if(curr >= 0 && curr <= jugsCombinedMax && valVis[curr] == false){
                    q.push(curr);
                    valVis[curr] = true;
                }
            }
        }

        return false;
    }
};