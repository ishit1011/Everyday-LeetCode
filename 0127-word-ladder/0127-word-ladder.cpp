class Solution {
public:
    int ladderLength(string bW, string eW, vector<string>& wordList) {
        queue<pair<string,int>> q;
        set<string> used(wordList.begin(),wordList.end());
        q.push({bW,1});
        used.erase(bW);
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            if(word == eW){
                return level;
            }
            for(int j=0; j<word.size(); j++){
                char ch = word[j];
                for(int i=0; i<26; i++){
                    word[j] = i + 'a';
                    if(used.find(word) != used.end()){
                        q.push({word,level+1});
                        used.erase(word);
                    }
                }
                word[j] = ch;
            }
        }
        return 0;
    }
};