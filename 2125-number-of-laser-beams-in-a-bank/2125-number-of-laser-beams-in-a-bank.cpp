class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size(), m = bank[0].size();
        vector<int> countOnes;
        int counter = 0;
        for(int i=0; i<n; i++){
            counter = count(bank[i].begin(),bank[i].end(),'1');
            countOnes.push_back(counter);
            counter = 0;
        }
        int ans = 0, prevCount = 0;
        for(int i=0; i<countOnes.size(); i++){
            if(countOnes[i] != 0){
                ans += (countOnes[i] * prevCount);
                prevCount = countOnes[i];
            }
            // cout<<i<<"--->"<<ans<<" & "<<countOnes[i]<<endl;
        }
        return ans;
    }
};