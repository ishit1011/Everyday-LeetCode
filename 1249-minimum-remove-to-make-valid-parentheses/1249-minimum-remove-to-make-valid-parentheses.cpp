class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> temp;
        int ltBrackets = 0, rtBrackets = 0;

        // 1. Count all Left and Right Brackets and remove extra Right Ones
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                ltBrackets++;
            }
            if(s[i] == ')'){
                rtBrackets++;
            }
            if(rtBrackets > ltBrackets){
                rtBrackets--;
                continue;
            }
            else{
                temp.push(s[i]);
            }
        }
        
        string res = "";
        // 2. Remove extra Left Brackets and return rest of them
        while(!temp.empty()){
            char currChar = temp.top();
            temp.pop();
            if(ltBrackets > rtBrackets && currChar == '('){
                ltBrackets--;
            }
            else{
                res += currChar;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};