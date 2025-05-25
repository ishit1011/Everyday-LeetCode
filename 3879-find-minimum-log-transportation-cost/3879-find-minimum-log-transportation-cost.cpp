class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long cost = 0;
        if(n > k){
            cout<<"n % k : "<<n%k<<" n / k : "<<n/k<<endl;
            long long rem = n % k;
            if(rem > 0){
                cost += (long long)(n % k) * k;
            }
            else{
                cost += (long long)k*k;
            }
        }
        if(m > k){
            long long rem = m % k;
            cout<<"m % k : "<<m%k<<" m / k : "<<m/k<<endl;
            if(rem > 0){
                cost += (long long)(m% k) * k;
            }
            else{
                cost += (long long)k*k;
            }
        }
        return cost;
    }
};