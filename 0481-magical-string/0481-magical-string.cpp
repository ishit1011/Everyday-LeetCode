class Solution {
public:
    int magicalString(int n) {
        // kolsavi sequence 
        // (add as many 1/2(opposite digit to last digit) as curr blocksize i.e current digit from str says)
        string str = "122";
        int remLen = n-3; // as block size starts from last digit of str i.e 2 in this case
        for(int i=2; i<remLen+3; i++){
            char lastChar = str[str.size()-1];
            int blocksize = str[i]-'0';
            if(lastChar == '1'){
                for(int j=0; j<blocksize; j++){
                    str += "2";
                }
            }
            else{
                for(int j=0; j<blocksize; j++){
                    str += "1";
                }
            }
        }
        int cntOne = 0;
        for(int i=0; i<n; i++){
            if(str[i] == '1') cntOne++;
        }
        cout<<str;
        return cntOne;
    }
};