class Solution {
public:
    bool checkLast(string str1, string str2){
        for(int i=0; i<str2.size(); i++){
            if(str2[i] != str1[i]){
                return false;
            }
        }
        return true;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        vector<string> ans;

        sort(folder.begin(),folder.end());
        ans.push_back(folder[0]);
        
        for(int i=1; i<n; i++){
            string last = ans.back();
            last += '/';
            if(!checkLast(folder[i],last)){
                ans.push_back(folder[i]);
            }
        }

        return ans;
    }
};