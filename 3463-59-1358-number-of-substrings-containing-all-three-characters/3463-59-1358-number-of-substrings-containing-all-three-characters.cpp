class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), l = 0, cnt = 0;
        vector<int> v(3,0);
        for(int r=0; r<n; r++){
            v[s[r]-'a']++;
            while(find(v.begin(),v.end(),0) == v.end()){
                v[s[l]-'a']--;
                // Most important thing is how much to increase count
                cnt += n-r;
                l++;
            }
        }
        return cnt;
    }
};