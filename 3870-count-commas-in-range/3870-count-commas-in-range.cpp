class Solution {
public:
    int countCommas(int n) {
        int cnt = 0;
        int m = n;
        while(n > 0){
            n /= 10;
            cnt++;
        }
        
        if(m > 999){
            int commas = cnt / 3, nums = m - 999;
            // cout<<"commas : "<<commas<<"\nnums : "<<(m-999)<<"\nmult : "<<(cnt/3) * (m-999);
            if(cnt % 3 == 0) return (commas-1) * nums;
            else return commas * nums;
        }
        return 0;
    }
};