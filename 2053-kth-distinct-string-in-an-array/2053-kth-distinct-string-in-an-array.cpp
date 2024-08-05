class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        for(string str : arr){
            mp[str]++;
        }
        int cnt = 0;
        for(string s : arr){
            if(mp[s] == 1){
                cnt++;
                if(cnt == k){
                    return s;
                }
            }
        }
        return "";
    }
};