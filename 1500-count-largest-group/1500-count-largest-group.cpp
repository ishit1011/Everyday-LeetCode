class Solution {
public:
    int digitSum(int num){
        int sum = 0;
        while(num>0){
            sum += num%10;
            num = num/10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        for(int i=1; i<=n; i++){
            int sum = digitSum(i);
            cout<<"sum : "<<sum<<endl;
            mp[sum]++;
        }
        int maxCount = INT_MIN;
        unordered_map<int,int> freqMp;
        int largestSize = 0;
        for(auto[x,y] : mp){
            largestSize = max(largestSize,y);
            freqMp[y]++;
        }
        for(auto[x,y] : freqMp){
            cout<<x<<" "<<y<<endl;
        }
        maxCount = freqMp[largestSize];
        return maxCount;
    }
};