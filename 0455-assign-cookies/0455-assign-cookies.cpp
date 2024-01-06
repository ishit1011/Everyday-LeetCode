class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size() == 0) return 0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int totalCookies = s.size();

        int count = 0;
        int cookiePointer = totalCookies - 1;
        int childDemandPointer = g.size() - 1;
        while(cookiePointer >= 0 && childDemandPointer >= 0){
            if(s[cookiePointer] >= g[childDemandPointer]){
                count++;
                cookiePointer--;
                childDemandPointer--;
            }
            else{
                childDemandPointer--;
            }
        }
        return count;
    }
};