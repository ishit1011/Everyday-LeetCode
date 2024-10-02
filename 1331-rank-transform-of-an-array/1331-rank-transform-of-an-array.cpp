class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++){
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end());
        int cnt = 1;
        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            ans[v[i].second] = cnt;
            if(i<n-1 && v[i+1].first != v[i].first){
                cnt++;
            }
        }
        return ans;
    }
};