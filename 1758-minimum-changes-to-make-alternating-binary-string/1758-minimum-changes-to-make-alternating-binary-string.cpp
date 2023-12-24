class Solution {
public:
    int minOperations(string s) {
        int start0 = 0;
        int start1 = 0;

        for(int i=0; i<s.size(); i++){
            if(i % 2 == 0){     // Check --> Even Posn
                if(s[i] == '1'){
                    start0++;
                }
                else{
                    start1++;
                }
            }
            else{               // Check --> Odd Posn
                if(s[i] == '1'){
                    start1++;
                }
                else{
                    start0++;
                }
            }
        }
        return min(start0, start1);
    }
};