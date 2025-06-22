class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        int rem = n % k;
        if(rem != 0){
            int toAdd = k-rem;
            for(int i=1; i<=toAdd; i++){
                s += fill;
            }
        }
        int m = s.size();
        vector<string> ans;
        for(int i=0; i<=m-k; i+=k){
            int start = i;
            string str;
            for(int j=start; j<start+k; j++){
                str += s[j];
            }
            ans.push_back(str);
        }
        return ans;
    }
};