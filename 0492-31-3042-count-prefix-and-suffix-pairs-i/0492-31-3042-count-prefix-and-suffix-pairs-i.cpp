class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(words[i].size() > words[j].size()) continue;
                else{
                    if(words[j].find(words[i]) == 0 && words[j].rfind(words[i]) == words[j].size() - words[i].size()){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};