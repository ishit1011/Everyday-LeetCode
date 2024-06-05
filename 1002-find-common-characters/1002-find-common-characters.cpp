class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int> minFreq(26,INT_MAX);
        
        for(int i=0; i<words.size(); i++){
            vector<int> charCount(26,0);
            string str = words[i];

            for(int j=0; j<str.length(); j++){
                charCount[str[j]-'a']++;
            }
            for(int k=0; k<26; k++){
                minFreq[k] = min(charCount[k],minFreq[k]);
            }
        }

        for(int i=0; i<26; i++){
            while(minFreq[i] > 0){
                ans.push_back(string(1,'a' + i));
                minFreq[i]--;
            }
        }
        return ans;
    }
};