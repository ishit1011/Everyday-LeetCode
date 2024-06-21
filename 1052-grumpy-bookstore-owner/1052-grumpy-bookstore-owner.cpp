class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int min) {
        int n = customers.size();
        int start = 0, unsat = 0, maxUnsat = 0;

        // 1. Window with max possible unsatisfied customers
        for(int i=0; i<=n-min; i++){
            unsat = 0;
            int j = 0;
            while(j < min){
                unsat += customers[i+j] * grumpy[i+j];
                j++;
            }
            cout<<"Unsatisfied here : "<< unsat << endl;
            if(unsat > maxUnsat){
                start = i;
                maxUnsat = unsat;
            }
            cout<<"Max unatisfied : "<< maxUnsat << endl;
            cout<<"-------------\n";
            maxUnsat = max(unsat,maxUnsat);
        }
        int ans = maxUnsat;

        // 2. Adding those who were satisfied inside the sliding window
        int idx = start;
        while(idx < start+min){
            if(grumpy[idx] == 0){
                ans += customers[idx];
            }
            idx++;
        }

        cout<<"ans : "<<ans<<endl;
        int k = 0;

        // 3. Adding remaining satisfied customers
        while(k < n){
            if(k == start){
                k += min;
            }
            else{
                if(grumpy[k] == 0){
                    ans += customers[k];
                }
                k++;
            }
        }
        return ans;
    }
};