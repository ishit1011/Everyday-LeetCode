class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int m = code.size();
        vector<int> circular = code;
        circular.insert(circular.end(), code.begin(), code.end());
        circular.insert(circular.end(), code.begin(), code.end());
        int n = circular.size();
        for(int i=0; i<n; i++){
            cout<<circular[i]<<" ";
        }
        vector<int> ans;
        for(int i=m; i<m+m; i++){
            int sum = 0;
            if(k > 0){
                for(int x=i+1; x<=i+k; x++){
                    sum += circular[x];
                }
                ans.push_back(sum);
            }
            if(k < 0){
                int kk = abs(k);
                for(int x=i-1; x>=i-kk; x--){
                    sum += circular[x];
                }
                ans.push_back(sum);
            }
            if(k == 0){
                ans.push_back(0);
            }
        }
        return ans;
    }
};