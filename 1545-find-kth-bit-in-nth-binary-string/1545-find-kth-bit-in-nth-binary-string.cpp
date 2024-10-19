class Solution {
public:
    char findKthBit(int n, int k) {
        string word = "";
        for(int i=1; i<=n; i++){
            if(word.empty()){
                word += '0';
            }
            else{
                string prev = word;
                string invRev = "";
                for(char ch : word){
                    if(ch == '1') invRev += '0';
                    else invRev += '1';
                }
                reverse(invRev.begin(),invRev.end());
                word = prev + '1' + invRev;
            }
        }
        return word[k-1];
    }
};