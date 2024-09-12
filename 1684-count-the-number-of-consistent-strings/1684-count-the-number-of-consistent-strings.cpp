class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<int> aSet(allowed.begin(),allowed.end());
        int cnt = 0;
        for(string s : words){
            int flag = 0;
            for(char ch : s){
                if(aSet.find(ch) == aSet.end()){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                cnt++;
            }
        }
        return cnt;
    }
};