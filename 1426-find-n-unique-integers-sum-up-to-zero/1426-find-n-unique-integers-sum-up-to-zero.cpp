class Solution {
public:
    vector<int> sumZero(int n) {
        if(n == 1) return {0};
        vector<int> ans;
        int a = 1, b = -1;
        n -= 2;
        ans.push_back(a);
        ans.push_back(b);
        if(n % 2 != 0){
            ans.push_back(0);
            n--;
        }
        // now "n" is EVEN (all cases);
        int i = 2, j = -2;
        while(n > 0){
            ans.push_back(i);
            ans.push_back(j);
            i++;
            j--;
            n -= 2;
        }
        return ans;
    }
};