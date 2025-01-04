class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> firstOccIdx(26,-1);
        vector<int> lastOccIdx(26,-1);
        for(int i=0; i<s.size(); i++){
            if(firstOccIdx[s[i]-'a'] == -1){
                firstOccIdx[s[i]-'a'] = i;
            }
        }
        for(int i=s.size()-1; i>=0; i--){
            if(lastOccIdx[s[i]-'a'] == -1){
                lastOccIdx[s[i]-'a'] = i;
            }
        }
        int cnt = 0;
        for(int i=0; i<26; i++){
            if(firstOccIdx[i] != -1){
                int first = firstOccIdx[i], last = lastOccIdx[i];
                set<int> elements;
                for(int ptr=first+1; ptr<last; ptr++){
                    elements.insert(s[ptr]);
                }
                cnt += elements.size();
            }
        }
        return cnt;
    }
};