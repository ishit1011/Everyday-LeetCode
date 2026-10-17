class Solution {
public:
    int digitSum(int num){
        int sum = 0;
        while(num != 0){
            int lastDigit = num % 10;
            sum += lastDigit;
            num /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,pair<int,int>>> p;
        for(int i=0; i<n; i++){
            int num = nums[i];
            int d = digitSum(num);
            p.push_back({d,{nums[i],i}});
        }
        // O(n log n)
        sort(p.begin(),p.end());

        map<int,int> mp;
        for(int i=0; i<n; i++){
            int sum = p[i].first, oldIdx = p[i].second.second;
            mp[oldIdx] = i;
        }
        vector<bool> visited(n,false);
        int cntCycles = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                cntCycles++; // new cycle starts
                int j = i;
                while(!visited[j]){
                    visited[j] = true;
                    j = mp[j];
                }
            }
        }
        cout<<"cnt cycles : "<<cntCycles;
        return n-cntCycles;
    }
};