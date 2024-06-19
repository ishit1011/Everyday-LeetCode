class Solution {
public:
    bool allBloomed(vector<int>& bDay, int m, int k, int midDay){
        int noOfB = 0;
        int cnt = 0;
        for(int i=0; i<bDay.size(); i++){
            if(bDay[i] <= midDay){
                cnt++;
            }
            else{
                noOfB += (cnt / k);
                cnt = 0;
            }
        }
        noOfB += cnt/k;
        return (noOfB >= m);
    }
    int minDays(vector<int>& bDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        if(val > bDay.size()) return -1;
        int sDay = *min_element(bDay.begin(),bDay.end());
        int eDay = *max_element(bDay.begin(),bDay.end());

        while(sDay <= eDay){
            int midDay = (sDay + eDay)/2;
            if(allBloomed(bDay, m, k, midDay) == true){
                cout<<"e : "<<eDay<<endl;
                eDay = midDay - 1;
            }
            else{
                sDay = midDay + 1;
            }
        }
        return sDay;
    }
};