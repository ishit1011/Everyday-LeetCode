class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int c = 0, n = a.size();
        vector<bool> all(n+1,false);
        vector<int> ans(n,0);
        int cntCommn = 0;
        for(int i=0; i<n; i++){
            if(all[a[i]]) cntCommn++;
            else all[a[i]] = true;

            if(all[b[i]]) cntCommn++;
            else all[b[i]] = true;

            ans[i] = cntCommn;
        }
        
        return ans;
    }
};