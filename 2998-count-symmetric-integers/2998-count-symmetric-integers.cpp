class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i=low; i<=high; i++){
            string str = to_string(i);
            int n = str.size();
            // even count of digits
            if(n % 2 == 0){
                int mid = n/2;
                int numLeft = 0;
                int numRight = 0;
                for(int i=0; i<mid; i++){
                    numLeft += str[i]-'0';
                }
                for(int i=mid; i<str.size(); i++){
                    numRight += str[i]-'0';
                }
                if(numLeft == numRight) count++;
            }
        }
        return count;
    }
};