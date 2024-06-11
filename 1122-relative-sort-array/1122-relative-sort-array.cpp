class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a1, vector<int>& a2) {
        int n2 = a2.size(), n1 = a1.size();
        vector<int> ans;
        for(int i=0; i<n1; i++){
            if(find(a2.begin(),a2.end(),a1[i]) == a2.end()){
                ans.push_back(a1[i]);
            }
        }
        sort(ans.begin(),ans.end());
        
        for(int i=n2-1; i>=0; i--){
            int cnt = count(a1.begin(),a1.end(),a2[i]);
            while(cnt != 0){
                ans.insert(ans.begin(),a2[i]);
                cnt--;
            }
        }
        return ans;
    }
};