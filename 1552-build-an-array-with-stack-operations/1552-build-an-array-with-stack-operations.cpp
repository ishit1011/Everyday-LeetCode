class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> stk;
        vector<string> ansSteps;
        for(int i=1; i<=n; i++){
            stk.push(i);
            ansSteps.push_back("Push");
            auto it = find(target.begin(), target.end(), i);
            if(it == target.end()){
                //NOT found
                stk.pop();
                ansSteps.push_back("Pop");
            }
            if(stk.size() == target.size()){
                break;
            }
        }
        return ansSteps;
    }
};