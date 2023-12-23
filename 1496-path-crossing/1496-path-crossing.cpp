class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        vector<pair<int,int>> isVisited;
        isVisited.push_back({x,y});

        for(auto it:path){
            if(it == 'N')y++;
            else if(it == 'S')y--;
            else if(it == 'E')x++;
            else if(it == 'W')x--;
            isVisited.push_back({x,y});
        }

        set<pair<int,int>>st(isVisited.begin(),isVisited.end());
        // All unique points in visited set
        if(isVisited.size() == st.size()){
            return false;
        }
        // At least 1 common point in visited set
        else{
            return true;
        }
    }
};