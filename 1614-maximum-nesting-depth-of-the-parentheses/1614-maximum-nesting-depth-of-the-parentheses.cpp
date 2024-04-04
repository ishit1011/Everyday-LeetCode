class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        for(int i=0; i<s.size(); i++){
            int leftBrackets = 0, rightBrackets = 0;
            for(int j=i; j>=0; j--){
                if(s[j] == '('){
                    leftBrackets++;
                }
                if(s[j] == ')'){
                    rightBrackets++;
                }
            }
            maxDepth = max(maxDepth,leftBrackets-rightBrackets);
        }
        return maxDepth;
    }
};