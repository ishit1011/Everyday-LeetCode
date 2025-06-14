class Solution {
public:
    int minMaxDifference(int num) {
        string number = to_string(num);
        int n = number.size();
        char maxReplace;
        int maxIdx = 0;
        for(int i=0; i<n; i++){
            if(number[i] != '9'){
                maxReplace = number[i];
                maxIdx = i;
                number[i] = '9';
                break;
            }
        }
        for(int i=maxIdx+1; i<n; i++){
            if(number[i] == maxReplace){
                number[i] = '9';
            }
        }
        string number2 = to_string(num);
        char minReplace;
        int minIdx = 0;
        for(int i=0; i<n; i++){
            if(number2[i] != '0'){
                minReplace = number2[i];
                minIdx = i;
                number2[i] = '0';
                break;
            }
        }
        for(int i=minIdx+1; i<n; i++){
            if(number2[i] == minReplace){
                number2[i] = '0';
            }
        }
        int num1 = stoi(number), num2 = stoi(number2);
        return num1-num2;
    }
};