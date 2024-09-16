class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minVec;
        for(string str : timePoints){
            string hours = "";
            string minutes = "";
            for(int i=0; i<2; i++){
                hours += str[i];
            }
            for(int j=3; j<5; j++){
                minutes += str[j];
            }
            int hr = stoi(hours);
            int mint = stoi(minutes);
            int total = hr * 60 + mint;
            minVec.push_back(total);
        }
        sort(minVec.begin(),minVec.end());
        int n = minVec.size();
        int diff = INT_MAX;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int sub = minVec[j]-minVec[i];
                if(sub > 720){
                    sub = (minVec[i]+1440-minVec[j]);
                }
                diff = min(diff,sub);
            }
        }
        return diff;
    }
};