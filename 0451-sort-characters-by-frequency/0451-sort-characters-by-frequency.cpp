class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mapping;
        // 1.   Insert every element according to its frequency in string "s"
        for(int i=0; i<s.size(); i++){
            mapping[s[i]]++;
        }
        // 2.   Insert the elements of the "map" to a vector pair and 
        //      sort it in a descending order
        vector<pair<char,int>> myVec(mapping.begin(),mapping.end());
        sort(myVec.begin(),myVec.end(), [](const auto &a, const auto &b) {
        return a.second > b.second;
        });
        // 3.   Insert the elememnts of the vector pair into the "ans"
        //      string one by one
        string ans;
        for(auto p : myVec){
            ans += string(p.second,p.first);
        }
        return ans;
    }
};