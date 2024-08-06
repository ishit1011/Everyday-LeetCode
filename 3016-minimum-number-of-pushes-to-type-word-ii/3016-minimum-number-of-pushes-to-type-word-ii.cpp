class Solution {
public:
    int minimumPushes(string word) {
        sort(word.begin(),word.end());
        vector<int> mp(26,0);
        for(char& ch : word){
            mp[ch-'a']++;
        }

        int ans = 0;
        sort(mp.rbegin(),mp.rend());
        for(int i=0; i<26; i++){
            if(mp[i] == 0) break;
            cout<<ans;
            ans += (i/8 + 1) * mp[i];
        }
        return ans;
    }
};