class Solution {
public:
    int checkArr(vector<int>& arr1, vector<int>& arr2, int val){
        int cnt = 0;
        for(int i=0; i<arr1.size(); i++){
            if(arr1[i] != val && arr2[i] == val){
                cnt++;
            }
            if(arr1[i] != val && arr2[i] != val){
                return -1;
            }
        }
        return cnt;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int> mpTops, mpBottom;
        for(int i=0; i<tops.size(); i++){
            mpTops[tops[i]]++;
            mpBottom[bottoms[i]]++;
        }
        int maxTops = 0, maxTopsCnt = 0;
        for(auto [x,y] : mpTops){
            if (maxTopsCnt < y) {
                maxTops = x;
                maxTopsCnt = y;
            }
        }
        cout<<"maxTops : "<<maxTops<<endl;
        int topsAns = checkArr(tops,bottoms,maxTops);

        int maxBottom = 0, maxBottomCnt = 0;
        for(auto [x,y] : mpBottom){
            if (maxBottomCnt < y) {
                maxBottom = x;
                maxBottomCnt = y;
            }
        }
        cout<<"maxBottom : "<<maxBottom<<endl;
        int bottomsAns = checkArr(bottoms,tops,maxBottom);

        if(topsAns == -1 && bottomsAns == -1 ) return -1;
        if(topsAns == -1 && bottomsAns != -1) return bottomsAns;
        if(topsAns != -1 && bottomsAns == -1) return topsAns;
        return min(bottomsAns,topsAns);
    }
};