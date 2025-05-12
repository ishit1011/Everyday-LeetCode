class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> res;
        set<int> digitsSet;
        for(int i=0; i<n; i++){
            int num = 0;
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(i != j && j != k && i != k && digits[i] != 0 && digits[k] % 2 == 0){
                        num = digits[i]*100 + digits[j]*10 + digits[k];
                        digitsSet.insert(num);
                    }
                }
            }
        }
        for(int i : digitsSet){
            res.push_back(i);
        }
        return res;
    }
};