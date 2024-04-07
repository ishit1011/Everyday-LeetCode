class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftBrackets;
        stack<int> asterisks;

        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                leftBrackets.push(i);
            }
            else if(s[i] == '*'){
                asterisks.push(i);
            }
            else{
                if(!leftBrackets.empty()){
                    leftBrackets.pop();
                }
                else if(!asterisks.empty()){
                    asterisks.pop();
                }
                else{
                    return false;
                }
            }
        }

        while(!leftBrackets.empty() && !asterisks.empty()){
            if(leftBrackets.top() > asterisks.top()){
                return false;
            }
            leftBrackets.pop();
            asterisks.pop();
        }
        return leftBrackets.empty();
    }
};