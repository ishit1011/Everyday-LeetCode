class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<int,int> mp;
        int n = word.size();
        for(int i=0; i<n; i++){
            mp[word[i]]++;
        }
        vector<int> arr;
        for(auto [x,y] : mp){
            arr.push_back(y);
        }
        sort(arr.begin(),arr.end());
        int minDeletions = INT_MAX, m = arr.size();
        /*
            For each frequency in the sorted list, we treat it as a potential "base" frequency.
            We then calculate how many deletions would be needed to make all other frequencies fall within the range 
            [base, base + k]:
            For frequencies smaller than the base: We must delete all of them (since we can't increase frequencies, 
            only decrease)
            For frequencies larger than base + k: We reduce them to exactly base + k by deleting the excess characters
            We keep track of the minimum deletions needed across all possible base frequencies
        */
        for(int i=0; i<m; i++){
            int base = arr[i];
            int totalDeletions = 0;
            // For number smaller than current freq
            for(int j=0; j<i; j++){
                totalDeletions += arr[j];
            }
            // For numbers larger than current freq
            for(int j=i+1; j<m; j++){
                if(arr[j] > base+k){
                    int diff = arr[j]-k-base;
                    totalDeletions += diff;
                }
            }
            minDeletions = min(minDeletions,totalDeletions);
        }
        return minDeletions;
    }
};