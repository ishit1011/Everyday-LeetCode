class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Store --> sorted version of each string (anagram) as the key
        //           index of the corresponding group in the answer vector 
        //           as the value
        unordered_map<string,int> map;
        vector<vector<string>> ans;

        for(int i=0; i<strs.size(); i++){
            string tempStr = strs[i]; 
            sort(tempStr.begin(),tempStr.end()); // // sort its characters alphabetically
            /* Check if the sorted string exists in the unordered map
                    1.  If YES --> add the current string to the corresponding 
                        group in the answer vector
                    2.  If NO --> create a new group and store its index in the unordered map
            */
            if(map.find(tempStr) != map.end()){
                ans[map[tempStr]].push_back(strs[i]);
            }
            else{
                map[tempStr] = ans.size();
                ans.push_back({strs[i]});
            }
        }
        return ans;
    }
};