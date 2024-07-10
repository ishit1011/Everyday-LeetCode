class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        stack<string> stk;
        for(const string& st : logs){
            if(st == "../"){
                if(!stk.empty()){
                    stk.pop();
                }
            }
            else if(st != "./"){
                stk.push(st);
            }
        }
        return stk.size();
    }
};