class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n % 2 != 0) return false;
        // Wildcard Stack : all elements that havn't been flipped
        stack<int> lockedOpenIdx, wildcardIdx;
        for(int i=0; i<n; i++){
            if(locked[i] == '0'){
                wildcardIdx.push(i);
            }
            else if(s[i] == '('){
                lockedOpenIdx.push(i);
            }
            else if(s[i] == ')'){
                if(!lockedOpenIdx.empty()){
                    lockedOpenIdx.pop();
                }
                else if(!wildcardIdx.empty()){
                    wildcardIdx.pop();
                }
                else{
                    return false;
                }
            }
        }

        while(!lockedOpenIdx.empty() && !wildcardIdx.empty() && lockedOpenIdx.top() < wildcardIdx.top()){
            lockedOpenIdx.pop();
            wildcardIdx.pop();
        }

        if(!lockedOpenIdx.empty()){
            return false;
        }
        return true;
    }
};