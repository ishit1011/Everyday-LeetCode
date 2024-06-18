class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        int n = p.size();
        int m = w.size();
        vector<pair<int,int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({p[i],d[i]});
        }
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());

        // ----- IMP (minimise difficulty at each index according to next & curr difficulty)
        for(int i=0; i<n-1; i++){
            vec[i+1].second = min(vec[i].second, vec[i+1].second);
        }
        
        int ans = 0;
        for(int i=0; i<m; i++){
            int low = 0, high = n-1, tempPft = 0;
            while(low <= high){
                int mid = (low + high)/2;
                if(vec[mid].second <= w[i]){
                    high = mid-1;
                    tempPft = max(tempPft,vec[mid].first);
                }
                else{
                    low = mid+1;
                }
            }
            ans += tempPft;
        }
        return ans;
    }
};