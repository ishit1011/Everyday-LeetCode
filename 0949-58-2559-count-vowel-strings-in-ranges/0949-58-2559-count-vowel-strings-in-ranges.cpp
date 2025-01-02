class Solution {
public:
    bool checkVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> prefixVowel(words.size() + 1, 0); 
        for (int j = 0; j < words.size(); j++) {
            string str = words[j];
            int len = str.length();
            if (checkVowel(str[0]) && checkVowel(str[len - 1])) {
                prefixVowel[j + 1] = prefixVowel[j] + 1;
            } else {
                prefixVowel[j + 1] = prefixVowel[j]; 
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            int startIdx = queries[i][0], endIdx = queries[i][1];
            ans.push_back(prefixVowel[endIdx+1]-prefixVowel[startIdx]);
        }
        return ans;
    }
};